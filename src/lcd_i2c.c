
#include "stm32f407xx.h"
#include "lcd_i2c.h"
#include <stdint.h>

static void lcd_send_nibble(uint8_t nibble, uint8_t control);

void delay_simple(uint32_t count) {
    while (count--) __asm("nop");
}

void i2c1_init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    // PB6 = I2C1_SCL, PB7 = I2C1_SDA
    GPIOB->MODER &= ~((3 << (6 * 2)) | (3 << (7 * 2)));
    GPIOB->MODER |= (2 << (6 * 2)) | (2 << (7 * 2)); // alternate function
    GPIOB->AFR[0] |= (4 << (6 * 4)) | (4 << (7 * 4));
    GPIOB->OTYPER |= (1 << 6) | (1 << 7); // open-drain
    GPIOB->OSPEEDR |= (3 << (6 * 2)) | (3 << (7 * 2)); // high speed
    GPIOB->PUPDR |= (1 << (6 * 2)) | (1 << (7 * 2)); // pull-up

    I2C1->CR2 = 16; // 16 MHz
    I2C1->CCR = 80; // 100kHz (modo standard)
    I2C1->TRISE = 17; // máx. subida (1000ns)
    I2C1->CR1 = I2C_CR1_PE;
}

void i2c1_write(uint8_t addr, uint8_t data) {
    while (I2C1->SR2 & I2C_SR2_BUSY);
    I2C1->CR1 |= I2C_CR1_START;
    while (!(I2C1->SR1 & I2C_SR1_SB));

    I2C1->DR = addr << 1;
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    (void)I2C1->SR2;

    while (!(I2C1->SR1 & I2C_SR1_TXE));
    I2C1->DR = data;
    while (!(I2C1->SR1 & I2C_SR1_BTF));

    I2C1->CR1 |= I2C_CR1_STOP;
}

void lcd_send_nibble(uint8_t nibble, uint8_t control) {
    uint8_t data = (nibble & 0xF0) | control | LCD_BACKLIGHT;
    i2c1_write(PCF8574_ADDR, data | LCD_ENABLE);
    delay_simple(2000);
    i2c1_write(PCF8574_ADDR, data & ~LCD_ENABLE);
    delay_simple(2000);
}

void lcd_send_cmd(uint8_t cmd) {
    lcd_send_nibble(cmd & 0xF0, 0);
    lcd_send_nibble(cmd << 4, 0);
    delay_simple(2000);
}

void lcd_send_data(uint8_t data) {
    lcd_send_nibble(data & 0xF0, LCD_RS);
    lcd_send_nibble(data << 4, LCD_RS);
    delay_simple(2000);
}

void lcd_send_string(const char *str) {
    while (*str) {
        lcd_send_data((uint8_t)*str++);
    }
}

void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t addr = (row == 0) ? 0x00 : 0x40;
    lcd_send_cmd(0x80 | (addr + col));
}

void lcd_init(void) {
    delay_simple(50000);
    lcd_send_nibble(0x30, 0); delay_simple(10000);
    lcd_send_nibble(0x30, 0); delay_simple(10000);
    lcd_send_nibble(0x30, 0); delay_simple(10000);
    lcd_send_nibble(0x20, 0); delay_simple(10000); // 4-bit

    lcd_send_cmd(0x28); // 4-bit, 2-line, 5x8 font
    lcd_send_cmd(0x0C); // Display ON, cursor OFF
    lcd_send_cmd(0x01); // Clear display
    delay_simple(20000);
    lcd_send_cmd(0x06); // Entry mode set
}

void i2c_scan(void) {
    for (uint8_t addr = 1; addr < 127; addr++) {
        while (I2C1->SR2 & I2C_SR2_BUSY);
        I2C1->CR1 |= I2C_CR1_START;
        while (!(I2C1->SR1 & I2C_SR1_SB));
        I2C1->DR = addr << 1;

        delay_simple(30000); // Curto delay

        if (I2C1->SR1 & I2C_SR1_ADDR) {
            (void)I2C1->SR2;
            GPIOD->ODR ^= (1 << 12);  // Pisca o LED se encontrar
            delay_simple(500000);
        }

        I2C1->CR1 |= I2C_CR1_STOP;
    }
}
