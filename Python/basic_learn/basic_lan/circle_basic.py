n = input("请输入整数N:")
sum = 0
for i in range(int (n)):
    sum += i+1;
print("1到N求和的结果:",sum)

for i in range(1,10):
    for j in range(1,i+1):
        print("{}*{}={:2}".format(j,i,i*j),end='')
    print('')
    
sum,tmp = 0,1
for i in range(1,11):
    tmp *=i
    sum +=tmp
print("运算结果是:{}".format(sum))
print(".....:",sum)

n =1
for i in range(5,0,-1):
    n = (n+1)<<1
    print(n)
print(n)