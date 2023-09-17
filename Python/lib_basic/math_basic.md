# 导入

```python 
import math
lst = dir(math)
```

# pi & e

```python
print("pi & e")
pi = math.pi
e  = math.e
print(pi)
print(e)
```

# 上下取整
```python 
print("上下取整")
ceil_num = math.ceil(3.5)
floor_num = math.floor(3.5)
print(ceil_num)
print(floor_num)

```

# 乘方 & 开方

```python 
print("乘方 & 开方")
print(math.pow(3,2),math.pow(2,4))  # def pow(__x: _SupportsFloatOrIndex, __y: _SupportsFloatOrIndex) -> float: ...
print(3**2,2**4)    # 得到int  然而print(3**2==math.pow(3,2)) # True
print(math.sqrt(9),math.sqrt(16))
```

# 弧度 & 角度

```python
print("弧度 & 角度")
dge = math.degrees(3.141592653589793)
rds = math.radians(180)

print(dge,rds)
```

# sin(x) 、cos(x)、 tan(x)、 tanh(x)、 sinh(x)、 cosh(x) ...

```python3
print("sin(x) cos(x) tan(x) tanh(x) sinh(x) cosh(x)")
print(math.sin(math.pi/2),"...")
print(math.sinh(math.pi/2),"...")
```

