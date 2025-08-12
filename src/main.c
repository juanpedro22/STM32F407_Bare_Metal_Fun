#include "stm32f407xx.h"
#include "system_stm32f4xx.h"
#include "timebase.h"
#include "lcd_i2c.h"
#include "uart.h"
#include <stdio.h>

void log_message(char *message_lcd_line1, char *message_lcd_line2, char *uart)
{ 
    lcd_set_cursor(0, 0);
    lcd_send_string(message_lcd_line1);
    lcd_set_cursor(1, 0);
    lcd_send_string(message_lcd_line2);

    printf("%s\r\n", uart); // Envia mensagem para o console UART

}

int main(void) {
    SystemInit();               // Inicializa clocks e FPU se necessário
    timebase_init(1000);        // Configura SysTick para 1ms
    i2c1_init();
    lcd_init();
    uart_tx_init();

    log_message("System Init", "normal mode", "System Init");
    delay_ms(2000);

    RCC->AHB1ENR |= (1 << 3);   // Habilita clock do GPIOD
    GPIOD->MODER &= ~(0x3 << (12 * 2)); // Limpa bits do pino 12
    GPIOD->MODER |=  (0x1 << (12 * 2)); // Define como saída


    log_message("Blinking LED", "Press any key", "Blinking LED waiting command");
    delay_ms(2000);


    while (1) {
        GPIOD->ODR ^= (1 << 12); // Toggle LED
        delay_ms(500);
    }

  

}
