assume ss:stack,cs:code
stack segment
        dw 0 dup(8)
stack ends

code segment
start:
        mov ax,stack
        mov ss,ax
        mov sp,10h
        mov ax,4240h
        mov dx,0fh
        mov cx,0ah

    call div_m
    
        mov ax,4c00h
        int 21h
div_m:
        push ax
        mov ax,dx
        mov dx,0    ;不影响后面的余数判断,使得高16位为0
        div cx      
        mov bx,ax
        pop ax
        div cx

        mov cx,dx
        mov dx,bx

        pop ax
        ret

code ends

end start