# tuple
tuple_t = (1, 2, 3)
tuple_t = 1, 2, 3, 4, 5, 5, 5, 5, 5
tuple_t_2 = 1,  # 逗号即可表示其是一个元组
a = ()  # 表示空元组
b = (1,)  # 表示元组
b1 = (1)  # 表示一个整数
# 元组的容器空间不可变

print("{}".format(tuple_t.count(5)))
# count()是计算元组或列表中元素出现的次数
print("{}".format(tuple_t.index(5)))
# index()是给出所选元素第一次出现的位置

# dict
d = {'a': 'b', 'c': 12, 'd': {'aa': 'bb', 'cc': 24, 'd': 'null'}}

print(d)
print(d['d'])
d['c'] = 22
print(d)
# 修改key 'c' 对应的值
d.pop('d')
print(d)
# 删除字典元素

a = set("qwertyuiop")
print(a)
# 把字符串转化成集合
c = [1, 2, 3, 4, 23, 4, 64, 36, 43]
e = set(c)
# 把列表转化为集合
print(list(e))
# 去掉重复元素
