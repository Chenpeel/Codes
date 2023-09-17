assume ds:data,cs:code

data segment 
    db 'Welcome to masm!',0
data ends

code segment

start:

        mov dh , 8 
        mov dl , 3
        mov cl , 2
        mov ax , data
        mov ds , ax
        mov si , 0
    call show_str

        mov ax,4c00h
        int 21h

show_str:
        push cx
        push si
change:
        mov al,0A0h

        dec dh      ;行号 -1
        mul dh
        mov bx,ax

        mov al,2
        mul dl
        sub ax,2

        add bx,ax
        
        mov ax,0B800h
        mov es,ax

        mov di,0
        
        mov al,2

        mov ch,0

    s:  mov cl,ds:[si]
    
        jcxz ok

        mov es:[bx+di],cl 
        mov es:[bx+di+1],al

        inc si

        add di ,2
        jmp short s

ok:     
        pop si
        pop cx
        ret

code ends

end start