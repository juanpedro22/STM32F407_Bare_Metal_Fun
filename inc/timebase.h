#ifndef TIMEBASE_H
#define TIMEBASE_H

#include <stdint.h>

void timebase_init(uint32_t systick_hz);
uint32_t get_tick(void);
void delay_ms(uint32_t ms);

#endif
