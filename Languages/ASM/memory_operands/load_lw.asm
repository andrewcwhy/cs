.text
    .globl  main
main:
    # Memory Operands
    # Load: Copies data from memory to a register
    # lw destination, constant(register)
    # The “load word” instruction takes the sum of the constant and the register to determine a memory address.
    # The data at this address is placed in the destination register.

    # A is an array of 100 words
    # g is a variable in $s1
    # h is a variable in $s2
    # Base address of A is in $s3
    # First we have to transfer A[8] to a register.
    # A[8] is stored in memory address $s3 + 8*4

    # g = h + A[8]

    lw      $t0,    32($s3)         # t0 = A[8], 32 is Offset, $s3 is base register
    add     $s1,    $s2,        $t0 # g = h + A[8]
    sw      $t0,    48($s3)         # Store t0 in A[12]

    # A[12] = h + A[8]

    lw      $t0,    32($s3)         # t0 = A[8]
    add     $t0,    $s2,        $t0 # t0 = h + A[8]

    li      $v0,    10
    syscall