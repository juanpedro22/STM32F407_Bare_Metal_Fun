#include "stm32f4xx.h"

void delay(volatile unsigned int t) {
    while (t--);
}

int main(void) {
    // Habilita o clock do GPIO D (bit 3 em AHB1ENR)
    RCC->AHB1ENR |= (1 << 3);

    // Configura PD12 como output (bits 24 e 25 do MODER)
    GPIOD->MODER &= ~(0x3 << (12 * 2));
    GPIOD->MODER |=  (0x1 << (12 * 2));

    while (1) {
        GPIOD->ODR ^= (1 << 12); // Toggle LED
        delay(1000000);
    }
}
