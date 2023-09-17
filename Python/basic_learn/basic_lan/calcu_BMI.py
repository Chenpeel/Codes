#the first version of bmi_cau 
from math import pow
height, weight = eval(
    input("please input heigth(meter) and weight(kilo) with ',' inside:"))
bmi = weight / pow(height, 2)
print("The bmi is {:.2f}".format(bmi))
wto, dom = "pianshou", "painshou"
if bmi < 18.5:
    pass
elif 18.5 <= bmi < 24:
    wto = dom = "normal"
elif 24 <= bmi < 25:
    wto, dom = "normal", "little fat"
elif 25 <= bmi < 28:
    wot = dom = "li fat"
elif 28 <= bmi < 30:
    wto, dom = "li fat", "fat"
else:
    wto = dom = "fat"
print("Acconding to the international standard:'{0}','{1}'".format(wto, dom))
