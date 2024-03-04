from PIL import Image

# 打开.webp图像
webp_image_path = 'hand.webp'
webp_image = Image.open(webp_image_path)

# 将白色改为透明
png_image = webp_image.convert('RGBA')
data = png_image.getdata()

new_data = []
for item in data:
    # 将白色改为透明，设置一个容差值
    if all(channel > 200 for channel in item[:3]):
        new_data.append((255, 255, 255, 0))
    else:
        new_data.append(item)

png_image.putdata(new_data)

# 保存为.png
png_image_path = 'output_image.png'
png_image.save(png_image_path, 'PNG')

# 关闭图像
webp_image.close()
