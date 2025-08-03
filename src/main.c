#include "stm32f407xx.h"
#include "system_stm32f4xx.h"
#include "timebase.h"
#include "lcd_i2c.h"

int main(void) {
    SystemInit();               // Inicializa clocks e FPU se necessário
    timebase_init(1000);        // Configura SysTick para 1ms
    i2c1_init();
    lcd_init();

    lcd_set_cursor(0, 0);
    lcd_send_string("LCD OK");

    RCC->AHB1ENR |= (1 << 3);   // Habilita clock do GPIOD
    GPIOD->MODER &= ~(0x3 << (12 * 2)); // Limpa bits do pino 12
    GPIOD->MODER |=  (0x1 << (12 * 2)); // Define como saída


    lcd_set_cursor(0, 0);
    lcd_send_string("Hello, STM32!");
    lcd_set_cursor(1, 0);
    lcd_send_string("LCD via I2C :)");


    while (1) {
        GPIOD->ODR ^= (1 << 12); // Toggle LED
        delay_ms(500);
    }

  

}
