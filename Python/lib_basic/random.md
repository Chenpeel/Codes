`import random`

# 生成随机浮点数（0-1）
```python
random.random()
```

# 生成随机整数（1-10）
```python 
random.randint(1, 10)
```

# 生成随机浮点数（1-10）
```python 
random.uniform(1, 10)
```

# 将列表元素排序
```python 
lst = [12, 13, 14, 15, 16, 17]
random.shuffle(lst)
```

# 从列表中随机取出一个元素以及随机取出两个元素组成新的列表
```python
r1 = random.choice(lst)
lstr1 = random.choices(lst)
print(r1, lstr1)
```

# 设置随机数种子并生成整数
```python 
random.seed(10)
random.randint(10, 110)
```

