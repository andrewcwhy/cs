.text
    .globl  main
main:
    li      $s1,    4           # b = 4
    li      $s2,    28          # c = 28
    li      $s3,    9           # d = 9
    li      $s4,    7           # e = 7

    # Equation: a = (b + c) - (d + e)

    add     $t0,    $s1,    $s2 # t0 = b + c (4 + 28 = 32)
    add     $t1,    $s3,    $s4 # t1 = d + e (9 + 7 = 16)
    sub     $s0,    $t0,    $t1 # s0 = t0 + t1 = (32 - 16 = 16)

    # Result 16 is now in $s0

    li      $v0,    10          # Prepare to exit program
    syscall                     # Exit
