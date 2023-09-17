pm = eval (input("PM2.5值:"))
if pm <0 : 
    print("ERROR") 
elif 0<=pm<35:
    print("空气质量优质，适宜户外运动!")
elif 35<pm<=75:
    print("空气质量良好,宜少量运动!")
else:
    print("空气污染,尽量避免外出")