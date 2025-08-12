#ifndef UART_H
#define UART_H

#include <stdbool.h>

void uart_tx_init(void);


#define MAX_BUFFER 100

extern volatile char rx_buffer[MAX_BUFFER];
extern volatile uint8_t rx_index;
extern volatile bool frase_completa;

#endif