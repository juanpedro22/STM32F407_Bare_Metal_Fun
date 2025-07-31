#include <stdint.h>
#include "stm32f407xx.h"     // Inclui SystemCoreClock, IRQn_Type, etc.
#include "core_cm4.h"        // Inclui SysTick_Config

volatile uint32_t g_tick_ms = 0;

void timebase_init(uint32_t hz) {
    SysTick_Config(SystemCoreClock / hz);
}

void SysTick_Handler(void) {
    g_tick_ms++;
}

uint32_t get_tick(void) {
    return g_tick_ms;
}

void delay_ms(uint32_t ms) {
    uint32_t start = get_tick();
    while ((get_tick() - start) < ms);
}
