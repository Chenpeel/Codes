import math
def UP_DOWN(x):
    print(x,end ="\n")
    every_day_up = math.pow((1.0 + x), 365)
    every_day_drop = math.pow((1.0 - x), 365)
    print("up : {:.5f} \ndown : {:.5f}".format(every_day_up, every_day_drop))
UP_DOWN(0.001)

UP_DOWN(0.005)

UP_DOWN(0.01)


weekstr = "星期一星期二星期三星期四星期五星期六星期日"
weekid = eval(input("输入星期数字(num>0)\n")) 
if(weekid>7):
    weekid = weekid%7
pos = (weekid-1)*3
print(weekstr[pos:pos+3])
