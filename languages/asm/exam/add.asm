.text
    .globl  main
main:
    li      $t0,    9           # b
    li      $t1,    7           # c
    li      $t2,    4           # d
    li      $t3,    28          # e

    # Equation: a = b + C + d + e

    add     $t4,    $t0,    $t1
    add     $t4,    $t4,    $t2
    add     $t4,    $t4,    $t3

    move    $a0,    $t4
    li      $v0,    1
    syscall

    li      $v0,    10
    syscall