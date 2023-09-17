assume ds:data , cs:code , ss:stack

stack segment

stack ends

data segment
db 'conversation',0
data ends

code segment 

start:  
        mov ax,data
        mov ds,ax
        mov si,0    ;对ds:si所指单元中的字母
        mov cx,12   
        call captial;唤起转大写程序
        mov si,0
        call lower;唤起转小写

        mov ax,4c00h
        int 21h        

captial:
        push cx
        push di
changeC: 
        mov cl,[si]
        mov ch,0
        jcxz ok
        and byte ptr [si],11011111b
        inc si 
        jmp short changeC
ok:     
        pop di
        pop cx
        ret

lower:  
        push cx
        push si
changeL:
        mov cl,[si]
        mov ch,0
        jcxz ok
        or byte ptr [si],00100000b
        inc si
        jmp short lower
    ok: 
        pop si
        pop cx
        ret

code ends

end start

;也可以用栈的方式实现