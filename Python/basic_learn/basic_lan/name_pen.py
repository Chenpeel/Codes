# The most important function is the  ** turtle.write() **
# which could helpfully process our words into graph
# 

from turtle import *

setup(600,370,None,None)
hideturtle()
speed(1)
pensize(5)
pencolor("black")
info = "你好"
pu()
fd(-100)
pd()
for i in info:
    write(i,align="center",font=("宋体",70,"normal"))
    pu()
    fd(100)
done()
