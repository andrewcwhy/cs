    # Delayed branches work when branches are short
    # No porcessoruses a delayed branch of more than 1 cycle

    # Long branch delays

.text
    .globl  main


main:
    add     $4,     $5, $6
    beq     $1,     $2, 40

    li      $v0,    10
    syscall