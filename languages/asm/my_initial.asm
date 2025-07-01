.data
a_char: .byte   'A'

.text
        .globl  main

main:
    lb      $a0,    a_char
    li      $v0,    11      # Load syscall number 11 (print_char) into $v0
    syscall

    li      $v0,    10      # Load syscall number 10 (exit) into $v0
    syscall