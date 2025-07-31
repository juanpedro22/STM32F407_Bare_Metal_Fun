#include "system_stm32f4xx.h"

// Clock default: HSI = 16 MHz
uint32_t SystemCoreClock = 16000000;

void SystemInit(void) {
    // Habilita FPU se necessário
    #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
        SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  // Full access to CP10 and CP11
    #endif

    // Aqui você pode adicionar init de clock, PLL, etc.
    SystemCoreClockUpdate();  // Atualiza SystemCoreClock se necessário
}

void SystemCoreClockUpdate(void) {
    // Simples: mantemos 16 MHz se nada for configurado
    SystemCoreClock = 16000000;
}
