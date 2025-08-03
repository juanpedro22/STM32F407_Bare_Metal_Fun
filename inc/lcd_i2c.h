#ifndef LCD_I2C_H
#define LCD_I2C_H

#include <stdint.h>

#define PCF8574_ADDR     0x27  // Endereço I2C do PCF8574 (padrão 0x27)
#define LCD_BACKLIGHT    0x08
#define LCD_ENABLE       0x04
#define LCD_RW           0x02
#define LCD_RS           0x01

void lcd_init(void);
void lcd_send_cmd(uint8_t cmd);
void lcd_send_data(uint8_t data);
void lcd_send_string(const char *str);
void lcd_set_cursor(uint8_t row, uint8_t col);
void i2c1_init(void);
void i2c1_write(uint8_t addr, uint8_t data);
void i2c_scan(void);

#endif
