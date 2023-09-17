from turtle import *
home()
seth(90)
ht()
speed(100)
pencolor("red")
pensize(3)
pendown()
wid = 5
for i in range(99):
    fd(wid)
    left(90)
    wid+=5

pu()
clear()
home()
pd()
speed (100) 
pensize (5)
for x in range (100):
    forward(4*x)
    left (91)

pu()
clear()
home()
pd()
speed(100)
pensize(5)
colors = ["red","yellow", 'purple', 'blue']
for x in range (100):
    pencolor (colors[x%4])
    forward (4*x)
    left (91)

exitonclick()
