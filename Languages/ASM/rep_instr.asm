    # Representing Instructions

.text
    .globl  main

main:
    # op: operation code (opcode), 6 bits
    # rs: first source register number, 5 bits
    # rt: second source register number, 5 bits
    # rd: destination register number, 5 bits
    # shamt: shift amount, 5 bits
    # funct: function code (extends opcode), 6 bits 

    add $t0, $s1, $s2

    li      $v0,    10
    syscall