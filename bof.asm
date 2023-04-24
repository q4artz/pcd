section .data                       
    text db "Hello!",10          ;db == define bytes. 10 is the new line
                                 ; text is the name of memory
section .text
    global _start

_start:
        mov rax, 1                 ;  
        mov rdi, 1                 ;
        mov rsi, text              ; address of the string
        mov rdx, 7                 ; the count(length) of the string
        syscall                    ; request service from the kernel

        mov rax, 60
        mov rdi, 0
        syscall
