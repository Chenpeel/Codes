from  turtle  import *
#太阳花
left(90)
fillcolor("red")
begin_fill()
while True:
    forward(200)
    left(170)
    if(abs(pos())<1):
        break
end_fill()

seth(-108)
#五角星
fillcolor("yellow")
begin_fill()
while True:
    forward(200)
    left(144)
    if(abs(pos())<1):
        break
end_fill()


done()