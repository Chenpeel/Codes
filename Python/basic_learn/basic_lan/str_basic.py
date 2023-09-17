# TempCovert

tempstr = input("输入带符号的温度值:")
while tempstr[-1] not in ['N', 'n']:
    if tempstr[-1] in ['f', 'F']:
        C = (eval(tempstr[0:-1])-32)/1.8
        print("转换后的温度是:{:.2f}".format(C))
    elif tempstr[-1] in ['C', 'c']:
        F = (eval(tempstr[0:-1])*1.8 + 32)
        print("转换后的温度为:{:.2f}".format(F))
    else:
        print("format defalt")
    tempstr = input("继续转换输入温度值,输入exit退出")
    if tempstr == "exit": 
        exit(0)


