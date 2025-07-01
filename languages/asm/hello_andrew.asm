.data
my_name:    .asciiz "Andrew!"
greeting:   .asciiz "Hello, "

.text
            .globl  main

main:
    la      $a0,    greeting
    syscall

    la      $a0,    my_name
    li      $v0,    4
    syscall

    li      $v0,    10
    syscall