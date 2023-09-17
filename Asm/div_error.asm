assume cs:code

code segment 
start:
			;安装do0程序，设置中断向量表
			mov ax,cs
			mov ds,ax
			mov si,offset do0
			xor ax,ax
			mov cx,offset do0end-offset do0;设置do0为传输长度
			mov di,200h
			cld;正方向
			rep movsb
			mov ax,4c00h
			int 21h
do0:	jmp short do0start
			db "Overflow!"
			
do0start:	
			;显示字符串overflow！
			mov ax,cs
			mov ds,ax
			mov si,202h
			
			mov ax,0b800h
			mov es,ax
			mov di,12*160+36*2;指向中间位置
			
			mov cx,9
s:		
			mov al,[si]
			mov es:[di],al
			inc si
			add di,2
loop s
			
			mov ax,4c00h
			int 21h
do0end:nop

code ends

end start 
			
