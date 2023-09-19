def fib(n : int)->int:
    fpp = 0
    if n == 0:
        return fpp
    fp = 1
    if n == 1:
        return fp
    res = 0
    for i in range(2,n+1):
        res = fpp + fp
        fpp = fp
        fp = res 
    return res

def main()->None:
    n = 50
    for i in range(n+1):
        print(fib(i))
    return 

main()
