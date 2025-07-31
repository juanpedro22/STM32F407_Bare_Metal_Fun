#ifndef __CORE_CMINSTR_H
#define __CORE_CMINSTR_H

#ifdef __cplusplus
 extern "C" {
#endif

/** No Operation */
__attribute__((always_inline)) static inline void __NOP(void)
{
  __asm volatile ("nop");
}

/** Wait For Interrupt */
__attribute__((always_inline)) static inline void __WFI(void)
{
  __asm volatile ("wfi");
}

/** Wait For Event */
__attribute__((always_inline)) static inline void __WFE(void)
{
  __asm volatile ("wfe");
}

/** Set Event */
__attribute__((always_inline)) static inline void __SEV(void)
{
  __asm volatile ("sev");
}

/** Disable IRQ Interrupts */
__attribute__((always_inline)) static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i");
}

/** Enable IRQ Interrupts */
__attribute__((always_inline)) static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i");
}

/** Breakpoint */
__attribute__((always_inline)) static inline void __BKPT(uint8_t value)
{
  __asm volatile ("bkpt %0" : : "i"(value));
}

#ifdef __cplusplus
}
#endif

#endif /* __CORE_CMINSTR_H */
