#蒙特卡洛法求解pi值，数据量小时，精度低
from random import random
from math import sqrt
from time import *
DARTS  = 1000000
hits = 0.0
process_time()
for i in range(1,DARTS+1):
    x ,y = random(),random()
    dist = sqrt(x**2+y**2)
    if dist <= 1.0 :
        hits = hits +1
pi = 4 * (hits/DARTS)
print("Pi {:.5f}".format(pi))
print ("running time :{:5.5}s".format(process_time()))