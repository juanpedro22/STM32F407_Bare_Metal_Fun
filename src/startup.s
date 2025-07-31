.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global _start
.global Reset_Handler
.global _estack
.global SystemInit
.global main

.section .isr_vector, "a", %progbits
.type _start, %object
_start:
    .word _estack                /* Topo da stack */
    .word Reset_Handler          /* Reset */
    .word NMI_Handler            /* NMI */
    .word HardFault_Handler      /* Hard Fault */
    .word Default_Handler        /* MemManage */
    .word Default_Handler        /* BusFault */
    .word Default_Handler        /* UsageFault */
    .word 0                      /* Reserved */
    .word 0                      /* Reserved */
    .word 0                      /* Reserved */
    .word 0                      /* Reserved */
    .word Default_Handler        /* SVCall */
    .word Default_Handler        /* Debug Monitor */
    .word 0                      /* Reserved */
    .word Default_Handler        /* PendSV */
    .word SysTick_Handler        /* SysTick */
    
    /* IRQs (apenas os primeiros 10 para exemplo, pode expandir conforme necessário) */
    .word Default_Handler        /* IRQ0 */
    .word Default_Handler        /* IRQ1 */
    .word Default_Handler        /* IRQ2 */
    .word Default_Handler        /* IRQ3 */
    .word Default_Handler        /* IRQ4 */
    .word Default_Handler        /* IRQ5 */
    .word Default_Handler        /* IRQ6 */
    .word Default_Handler        /* IRQ7 */
    .word Default_Handler        /* IRQ8 */
    .word Default_Handler        /* IRQ9 */

.size _start, . - _start

.text
.thumb
.thumb_func
.type Reset_Handler, %function
Reset_Handler:
    LDR   R0, =_sidata
    LDR   R1, =_sdata
    LDR   R2, =_edata
1:
    CMP   R1, R2
    ITTT  lt
    LDRLT R3, [R0], #4
    STRLT R3, [R1], #4
    BLT   1b

    /* Zera a .bss */
    LDR   R0, =_sbss
    LDR   R1, =_ebss
    MOVS  R2, #0
2:
    CMP   R0, R1
    IT    lt
    STRLT R2, [R0], #4
    BLT   2b

    /* Chama SystemInit e main */
    BL SystemInit
    BL main

LoopForever:
    B LoopForever

.size Reset_Handler, . - Reset_Handler

/* Handlers fracos para interrupções */
.weak NMI_Handler
.weak HardFault_Handler
.weak SysTick_Handler
.weak Default_Handler

.thumb_func
NMI_Handler:
Default_Handler:
HardFault_Handler:
    B .

.thumb_func
SysTick_Handler:
    /* Incremente seu tick aqui se quiser */
    LDR R0, =g_tick_ms
    LDR R1, [R0]
    ADD R1, R1, #1
    STR R1, [R0]
    BX LR
