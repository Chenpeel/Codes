from math import radians

def cacu_sinx(x1):
    n = 0
    if x1 %180 == 0: 
        return 0;
    x = radians(x1)
    s = a = x
    while abs(a) >= 1e-15:
        a *= -x*x/(2*n+3)/(2*n+2)
        n += 1
        s += a
    return s

def cacu_cosx(x2):
    n = 0
    if (x2-90) %180 == 0: 
        return 0;
    x = radians(x2)
    s = a = 1
    while abs(a) >= 1e-15:
        a *= -x*x/(2*n+2)/(2*n+1)
        n += 1
        s += a
    return s

x1 = float(input("input angle rad: "))
s = cacu_cosx(x1)
print("x = {},cos(x) = {}".format(x1, s))
