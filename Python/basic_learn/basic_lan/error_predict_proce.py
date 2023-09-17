# try
try :
    num = eval(input("input a int_num:"))
    print(num ** 2)
except NameError:
    print("Input Error")
    

try :
    alp  = "QWERTYUIOPASDFGHJKLZXCVBNM"
    idx  = eval(input("input a int_num:"))
    print(alp[idx])
except NameError :
    print("Input Error")
else :
    print("I'm fine")
finally :
    print("Successfully Finish")
## else与except中的非此即彼
## finally 无论如何都会执行

#with

## 