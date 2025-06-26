.text
    .globl  main
main:
    li      $s1,    9           # b
    li      $s2,    7           # c
    li      $s2,    4           # d
    li      $s3,    28          # e

    # Equation: a = b + C + d + e

    add     $t0,    $s1,    $s2
    add     $t1,    $t0,    $s2
    add     $t2,    $t1,    $s3

    li      $v0,    10
    syscall