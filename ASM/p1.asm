section .data
    point1 db 10, 20
    point2 db 30, 40

section .text
    global _start

_start:
    ; Print point1
    mov eax, 4
    mov ebx, 1
    mov ecx, point1
    mov edx, 2
    int 0x80

    ; Print point2
    mov eax, 4
    mov ebx, 1
    mov ecx, point2
    mov edx, 2
    int 0x80

    ; Exit
    mov eax, 1
    xor ebx, ebx
    int 0x80