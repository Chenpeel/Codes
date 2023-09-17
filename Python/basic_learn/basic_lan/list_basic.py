list_a = ["今""日""无""事""勾""栏""听""曲"]
print(list_a[3:])
print(list_a[:])
print(list_a[0:-1])
print(list_a[::2])

list_a.append("浅影阿_")
#在末尾添加一个元素
list_a.extend(["a","a","a","!"])
#list.extend()可在末尾添加多个元素
list_a.insert(0,"w")
list_a.insert(1,"u")
list_a.insert(2,"~")
print(list_a)
#list.insert(pos,char)

list_a.pop()
print(list_a)
list_a.pop(-2)
print(list_a)
#list.pop()方法，可以带索引，或者直接pop出最后一个元素
list_a.remove("a")
print(list_a)
#删除重复的第一个元素，不存在就报错 
list_a.clear()
print(list_a)
#清表，但表仍存在
del list_a
try:
    print(list_a)
except :
    print("list has deleted")
    pass


diet = ['西红柿','花椰菜','黄瓜','牛排','虾仁']
for x in range(0,5):
    for y in range(0,5):
        if not (x==y):
            print("{}{}".format(diet[x],diet[y]))

