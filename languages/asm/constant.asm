.text
    .globl  main
main:

    addi    $s0,    $zero,  8   # s0 = 0 + 8

    # s = s + 4
    addi    $s0,    $s0,    4   # s0 = s0 + 4 (8 + 4 = 12)

    # Exit program
    li      $v0,    10
    syscall
 m     