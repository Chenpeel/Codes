#!/usr/bin/env bash
set -euo pipefail

usage() {
cat <<'EOF'
Usage:
sudo SRC_DISK=/dev/sda DST_DISK=/dev/nvme0n1 ./migrate.sh --initial
sudo SRC_DISK=/dev/sda DST_DISK=/dev/nvme0n1 ./migrate.sh --final
EOF
}

if [[ "${1:-}" != "--initial" && "${1:-}" != "--final" ]]; then
usage
exit 1
fi

if [[ $EUID -ne 0 ]]; then
echo "Run as root."
exit 1
fi

SRC_DISK="${SRC_DISK:-/dev/sda}"
DST_DISK="${DST_DISK:-/dev/nvme0n1}"

part() {
local disk="$1" num="$2"
if [[ "$disk" =~ [0-9]$ ]]; then
    echo "${disk}p${num}"
else
    echo "${disk}${num}"
fi
}

SRC_EFI="$(part "$SRC_DISK" 1)"
SRC_ROOT="$(part "$SRC_DISK" 2)"
DST_EFI="$(part "$DST_DISK" 1)"
DST_ROOT="$(part "$DST_DISK" 2)"

if [[ ! -b "$SRC_DISK" || ! -b "$DST_DISK" ]]; then
echo "Disk not found. SRC_DISK=$SRC_DISK DST_DISK=$DST_DISK"
exit 1
fi

if [[ ! -d /sys/firmware/efi ]]; then
echo "UEFI not detected. This script assumes UEFI."
exit 1
fi

EXCLUDES=(
"/dev/*" "/proc/*" "/sys/*" "/tmp/*" "/run/*"
"/mnt/*" "/media/*" "/lost+found"
)

rsync_copy() {
local delete_flag="${1:-}"
local args=()
for e in "${EXCLUDES[@]}"; do
    args+=(--exclude="$e")
done
rsync -aAXH --numeric-ids --info=progress2 ${delete_flag} "${args[@]}" / /mnt/dst/
}

mount_target() {
mkdir -p /mnt/dst
mountpoint -q /mnt/dst || mount "$DST_ROOT" /mnt/dst
mkdir -p /mnt/dst/boot/efi
mountpoint -q /mnt/dst/boot/efi || mount "$DST_EFI" /mnt/dst/boot/efi
}

update_fstab() {
local efi_uuid root_uuid fstab
efi_uuid="$(blkid -s UUID -o value "$DST_EFI")"
root_uuid="$(blkid -s UUID -o value "$DST_ROOT")"
fstab="/mnt/dst/etc/fstab"
cp -a "$fstab" "${fstab}.bak.$(date +%F-%H%M%S)"

awk -v ru="$root_uuid" -v eu="$efi_uuid" '
BEGIN {fr=0; fe=0}
$0 ~ /^[[:space:]]*#/ || NF<2 {print; next}
{
    if ($2=="/") { $1="UUID="ru; fr=1 }
    else if ($2=="/boot/efi") { $1="UUID="eu; fe=1 }
    print
}
END {
    if (!fr) print "UUID="ru" / ext4 errors=remount-ro 0 1"
    if (!fe) print "UUID="eu" /boot/efi vfat umask=0077 0 1"
}' "$fstab" > "${fstab}.tmp"
mv "${fstab}.tmp" "$fstab"
}

install_grub() {
for i in /dev /dev/pts /proc /sys /run; do
    mount --bind "$i" "/mnt/dst$i"
done
chroot /mnt/dst /bin/bash -c \
    "grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=ubuntu --recheck && update-grub"
}

if [[ "$1" == "--initial" ]]; then
root_src="$(findmnt -no SOURCE /)"
if [[ "$root_src" != "$SRC_ROOT" ]]; then
    echo "Root is $root_src, expected $SRC_ROOT. Set SRC_DISK correctly."
    exit 1
fi

echo "Disks:"
lsblk -o NAME,SIZE,MODEL "$SRC_DISK" "$DST_DISK"
read -r -p "This will erase $DST_DISK. Type ERASE to continue: " ans
[[ "$ans" == "ERASE" ]] || exit 1

parted -s "$DST_DISK" mklabel gpt
parted -s "$DST_DISK" mkpart ESP fat32 1MiB 1025MiB
parted -s "$DST_DISK" set 1 esp on
parted -s "$DST_DISK" mkpart primary ext4 1025MiB 100%

partprobe "$DST_DISK" || true
udevadm settle || true

mkfs.fat -F32 -n EFI "$DST_EFI"
mkfs.ext4 -L root "$DST_ROOT"

mount_target
rsync_copy
update_fstab

echo "Initial sync done."
echo "Next: switch to TTY, stop sddm (sudo systemctl stop sddm), then run:"
echo "  sudo SRC_DISK=$SRC_DISK DST_DISK=$DST_DISK $0 --final"
exit 0
fi

if systemctl is-active --quiet sddm; then
echo "sddm is still running. Stop it from TTY first:"
echo "  sudo systemctl stop sddm"
exit 1
fi

mount_target
rsync_copy --delete
install_grub
umount -R /mnt/dst

echo "Done. Reboot and set NVMe as first boot device."
