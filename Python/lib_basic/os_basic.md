# Python中常用的os模块

## 系统相关

- `os.name`：操作系统的名称，Windows系统返回"nt"，Linux/Unix系统返回"posix"；
- `os.environ`：操作系统环境变量的映射，通常用于查找环境变量的值；
- `os.sep`：操作系统特定的路径分隔符，Windows系统返回"\"，Linux/Unix系统返回"/"；
- `os.pathsep`：操作系统特定的路径分隔符，Windows系统返回";"，Linux/Unix系统返回":"；
- `os.linesep`：操作系统特定的行分割符，Windows系统返回"\r\n"，Linux/Unix系统返回"\n"。

## 文件和目录

### 创建、删除文件夹

- `os.mkdir(path)`：创建目录；
- `os.rmdir(path)`：删除目录（只能删除空目录）。

### 获取文件目录信息

- `os.stat(path)`：获取文件/目录的状态信息；
- `os.getcwd()`：获取当前工作目录；
- `os.listdir(path)`：列出指定目录下的文件和子目录的名称列表。

### 重命名

- `os.rename(src, dst)`：重命名文件或目录。

### 创建、删除文件

- `with open`：创建文件；
- `os.remove(path)`：删除文件。

## 路径

- `os.chdir(path)`：改变当前工作目录；
- `os.path.isabs(path)`：判断路径是否为绝对路径。

## 文件存在

- `os.path.isdir()`：判断是否是目录；
- `os.path.exists()`：判断文件是否存在。

## 文件大小字节数

- `os.path.getsize(path)`：获取文件大小。

## 文件名

- `os.path.dirname(path)`：获取完整路径中的目录部分；
- `os.path.basename(path)`：获取文件名或目录名。

## 时间相关

- `os.path.getatime(path)`：获取文件上一次访问时间；
- `os.path.getctime(path)`：获取文件创建时间；
- `os.path.getmtime(path)`：获取文件上一次修改时间。
