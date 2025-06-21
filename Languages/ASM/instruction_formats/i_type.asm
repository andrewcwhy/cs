.text
    .globl  main

main:

    lw $t0, 32($s32)

    li      $v0,    10
    syscall