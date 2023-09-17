import datetime,turtle

def draw_line (draw):
    turtle.pd() if draw else turtle.pu()
    turtle.fd(40)
    turtle.right(90)
    
def draw_dight(digit):
    draw_line(True) if digit in [2,3,4,5,6,8,9] else draw_line(False)
    draw_line(True) if digit in [0,1,3,4,5,6,7,8,9] else draw_line(False)
    draw_line(True) if digit in [0,2,3,5,6,8,9] else draw_line(False)
    draw_line(True) if digit in [0,2,6,8] else draw_line(False)
    turtle.left(90)
    draw_line(True) if digit in [0,4,5,6,8,9] else draw_line(False)
    draw_line(True) if digit in [0,2,3,5,6,7,8,9] else draw_line(False)
    draw_line(True) if digit in [0,1,2,3,4,7,8,9] else draw_line(False)
    turtle.left(180)
    turtle.pu()
    turtle.fd(20)

def draw_date(date):
    turtle.speed(100)
    turtle.pencolor("red")
    for i in date:
        draw_dight(eval(i))


def drawGap(): #绘制数码管间隔
    turtle.penup()
    turtle.fd(5)
def drawLine(draw):   #绘制单段数码管
    drawGap()
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(40)
    drawGap()    
    turtle.right(90)
def drawDigit(d): #根据数字绘制七段数码管
    drawLine(True) if d in [2,3,4,5,6,8,9] else drawLine(False)
    drawLine(True) if d in [0,1,3,4,5,6,7,8,9] else drawLine(False)
    drawLine(True) if d in [0,2,3,5,6,8,9] else drawLine(False)
    drawLine(True) if d in [0,2,6,8] else drawLine(False)
    turtle.left(90)
    drawLine(True) if d in [0,4,5,6,8,9] else drawLine(False)
    drawLine(True) if d in [0,2,3,5,6,7,8,9] else drawLine(False)
    drawLine(True) if d in [0,1,2,3,4,7,8,9] else drawLine(False)
    turtle.left(180)
    turtle.penup()
    turtle.fd(20) 
def drawDate(date):
    turtle.pencolor("red")
    for i in date:
        if i == '-':
            turtle.write('年',font=("Arial", 18, "normal"))
            turtle.pencolor("green")
            turtle.fd(40) 
        elif i == '=':
            turtle.write('月',font=("Arial", 18, "normal"))
            turtle.pencolor("blue")
            turtle.fd(40)
        elif i == '+':
            turtle.write('日',font=("Arial", 18, "normal"))
        else:
            drawDigit(eval(i))



def main():
    turtle.setup(1000,400,200,200)
    turtle.hideturtle()
    turtle.pu()
    turtle.fd(-300)
    turtle.pensize(5)
    turtle.pd()
    draw_date(datetime.datetime.now().strftime('%Y%m%d'))
    
    turtle.clear()
    
    turtle.penup()
    turtle.home()
    turtle.fd(-350)
    turtle.pensize(5)
    drawDate(datetime.datetime.now().strftime('%Y-%m=%d+'))
    turtle.hideturtle()
    turtle.done()
main()