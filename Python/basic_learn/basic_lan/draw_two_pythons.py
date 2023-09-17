from turtle import *

def drawSnake_python(radius,angle,length):
    seth(-40)
    for i in range(length):
        circle(radius,angle)
        circle(-radius,angle)
    circle(radius,angle/2)
    fd(40)
    circle(16,180)
    fd(40*2/3)
setup(650,350,200,200)
pu()
fd(-250)
pd()
pensize(25)
pencolor("yellow")
drawSnake_python(40,80,4)   

    
    
setup(650,350,200,200)
pu()
fd(450)
pd()
pensize(25)
pencolor("purple")
seth(-40)
for i in range(4):
    circle(40,80)
    circle(-40,80)
circle (40,80/2)
fd(40)
circle(16,180)
fd(40*2/3)


clear()
 
done()   
