import time 
scale = 20 
print("start")
for i in range(scale+1):
    a,b= '**' *i,'..'*(scale-i)
    c= (i/scale)*100
    print("%{:^3.0f}[{}->{}]".format(c,a,b))
    time.sleep(0.1)
print("The end")

for i in range(101):
    print ("\r{:2}%".format(i),end="")
    time.sleep(0.05)
time.sleep(1)
scale = 50
print("start".center(scale//2,'-'))
t= time.perf_counter()
for i in range(scale +1 ):
    a = '*' * i
    b = '.' * (scale-i)
    c = (i/scale) *100
    t -= time.perf_counter()
    print("\r{:^3.0f}%[{}->{}]{:.2f}s".format(c,a,b,t))
    time.sleep(0.05)
print("\n"+"The End".center(scale//2,'-'))