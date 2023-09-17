from math import sqrt

def getNum():
    nums=[]
    iNumStr = input("insert num(end with enter): ")
    while iNumStr !=" ":
        nums.append(eval(iNumStr))
        iNumStr = input("insert num(end with enter): ")
    return nums

def mean(numbers):  #aver
    s=0.0
    for num in numbers:
        s =s+num
    return s/len(numbers)

def dev(numbers,mean):  #vari
    sdev = 0.0
    for num in numbers:
        sdev += (num-mean)**2
    return sqrt(sdev/len(numbers)-1)

def median(numbers):    #mid
    sorted(numbers)
    size =len(numbers)
    if size%2 ==0:
        med = (numbers[size//2 -1]+ numbers[size//2])/2
    else:
        med = numbers[size//2]
    return med

n = getNum() #main()
m = mean(n)
print("平均:{},方差:{:.2},中位数:{}.".format(m,dev(n,m),mean(n)))
