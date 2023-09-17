#about turtle.pyi

#同切圆绘制
import turtle
turtle.setup(1000,1000,None,None)

"""turtle中的setup函数
turtle.setup(width,heigth,startx,starty)
其中startx,starty
分别代表窗口左侧与屏幕左侧的像素距离
顶部与屏幕顶部之间的像素距离
"""
turtle.goto(0,-320)
#turtle中的goto语句是turtle的可视移动，轨迹可见
turtle.pensize(1)
turtle.circle(10,180)
turtle.circle(-10,180)
turtle.circle(10,180)
turtle.circle(-10,180)
turtle.circle(10,180)
turtle.circle(-10,180)
#turtle.circle(radius,extent)半径和角度

turtle.seth(90)
turtle.setheading(90)
#seth(angle)只改变方向，而不移动,seth = setheading 

turtle.left(90)
turtle.fd(100)
#forward,前进
turtle.right(90)
turtle.fd(100)



#RGB turtle
turtle.up()
turtle.pu()
turtle.penup() 
#抬笔,turtle悬空,up = pu =  penup
turtle.pendown()
turtle.pd()
#落笔,turtle爬行 pd = pendown
turtle.pensize() 
turtle.width() 
#笔芯宽度,width = pensize
turtle.color('red')
#turtle颜色


print(turtle.pos())

turtle.setx(100)
turtle.sety(100)

turtle.home()
#返回原点













turtle.done()