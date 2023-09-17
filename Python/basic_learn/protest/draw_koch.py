from turtle import *

def koch(size,n):
    #自相似性
    if n== 0:
        fd(size)
    else :
        for angle in [0,60,-120,60]:
            left(angle)
            koch(size/3,n-1)

def _level():
    #snowy flowers
    setup(600,600)
    speed(100)
    penup()
    goto(-200, 100)
    pendown()
    pensize(2)
    level = 5
    koch(400,level) 
    right(120)
    koch(400,level)
    right(120)
    koch(400,level)
    hideturtle()
    clear()
    

def main ():
    _level()
    #snowy flower
    
    setup(800,400)
    speed(100)
    pu()
    goto(-300,-50)
    pd()
    pensize(2)
    koch(600,6)
    hideturtle()
main()



