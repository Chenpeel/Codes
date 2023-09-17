def factorial(num):
    if num == 0:
        return 1
    else:
        return num * factorial(num - 1)

# 利用列表存储递归过程的数据:
def factorial_li(num):
    l = [1, 1]
    for i in range(2, num+1):
        l.append(l[i-1]*i)
    return l[num]

n = eval(input("Input a intege number:"))
print(factorial(n))
print(factorial_li(n))




