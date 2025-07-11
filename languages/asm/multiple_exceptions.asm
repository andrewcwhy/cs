.data
numbers:    .word   10, 20, 30, 40, 50  # our array
length:     .word   5                   # number of elements
result:     .word   0                   # space to store the sum

.text
            .globl  main
main:
    # — Initialize pointers/counters
    la      $t0,    numbers             # $t0 = base address of numbers[]
    lw      $t1,    length              # $t1 = length (5)
    move    $t2,    $zero               # $t2 = sum accumulator = 0
    li      $t3,    0                   # $t3 = loop counter = 0

loop:
    # if ($t3 == $t1) goto end
    beq     $t3,    $t1,        end
    nop                                 # ← delay slot for the branch

    # load next array element
    lw      $t4,    0($t0)              # at this point, pipeline would stall one cycle
    # because the following ADD uses $t4 too soon
    add     $t2,    $t2,        $t4     # sum += numbers[i]

    # advance pointer/counter
    addi    $t0,    $t0,        4       # move to next word
    addi    $t3,    $t3,        1       # i++

    # loop back
    j       loop
    nop                                 # ← delay slot for jump

end:
    # store the computed sum
    sw      $t2,    result

    # print the sum (syscall 1: print_int)
    li      $v0,    1
    move    $a0,    $t2
    syscall

    # exit (syscall 10)
    li      $v0,    10
    syscall
