    .section .isr_vector,"a",%progbits
    .word _estack        // Topo da stack
    .word Reset_Handler  // Reset handler

    .text
Reset_Handler:
    bl main
    b .
