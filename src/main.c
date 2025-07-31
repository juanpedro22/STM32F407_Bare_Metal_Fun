#include "stm32f407xx.h"
#include "system_stm32f4xx.h"
#include "timebase.h"

int main(void) {
    SystemInit();               // Inicializa clocks e FPU se necessário
    timebase_init(1000);        // Configura SysTick para 1ms

    RCC->AHB1ENR |= (1 << 3);   // Habilita clock do GPIOD
    GPIOD->MODER &= ~(0x3 << (12 * 2)); // Limpa bits do pino 12
    GPIOD->MODER |=  (0x1 << (12 * 2)); // Define como saída

    while (1) {
        GPIOD->ODR ^= (1 << 12); // Toggle LED
        delay_ms(500);
    }
}
