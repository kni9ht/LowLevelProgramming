section .data
    hello: db "Hello World", 10
    helloLen: equ $-hello

section .text
global print

print:
    mov rax, 1
    mov rdi, 1
    mov rsi, hello
    mov rdx, helloLen
    syscall
    ret
