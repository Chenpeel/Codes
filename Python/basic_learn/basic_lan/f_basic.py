
# 计算圆的面积
PI = 3.1415926
radius = 25
area = PI * radius * radius
print(area)
print("{:.2f}".format(area))


#简单人名的对话
name = 'a'#input("请输入姓名:")
for i in range(3): 
#range(int)表示循环int次
    print("%s 同学,学好python,前途无量,大展拳脚,人见人爱" %name)


#斐波那契数列计算
a,b = 0,1
while a<10000000000:
    print(a,end=' ')
    a,b = b,a+b
print("\n")
#日期和时间的输出
from datetime import datetime
now = datetime.now()
print(now)
now.strftime("%x")
now.strftime("%x")

#九九乘法表
for i in range(1,10):
    for j in range (1,1+i):
        print("{}*{}={:2}".format(j,i,i*j),end= ' ')
    print('  ')
#format函数 "../Python.md"

        








