# nine_circle

import turtle
# 创建画布和画笔
canvas = turtle.Screen()
pen = turtle.Turtle()

# 循环画出九个同心圆，半径依次递增
for i in range(9):
    pen.up()
    pen.goto(0, -i * 10)
    pen.down()
    pen.circle((i + 1) * 10)

# 关闭画布
canvas.exitonclick()
