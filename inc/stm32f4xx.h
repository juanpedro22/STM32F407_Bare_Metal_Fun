#ifndef STM32F4XX_H
#define STM32F4XX_H

#define PERIPH_BASE     ((unsigned int)0x40000000)
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000)
#define GPIOD_BASE      (AHB1PERIPH_BASE + 0x0C00)
#define RCC_BASE        (AHB1PERIPH_BASE + 0x3800)

#define RCC   ((RCC_TypeDef *) RCC_BASE)
#define GPIOD ((GPIO_TypeDef *) GPIOD_BASE)

typedef struct {
    volatile unsigned int MODER;
    volatile unsigned int OTYPER;
    volatile unsigned int OSPEEDR;
    volatile unsigned int PUPDR;
    volatile unsigned int IDR;
    volatile unsigned int ODR;
    volatile unsigned int BSRR;
    volatile unsigned int LCKR;
    volatile unsigned int AFR[2];
} GPIO_TypeDef;

typedef struct {
    volatile unsigned int CR;
    volatile unsigned int PLLCFGR;
    volatile unsigned int CFGR;
    volatile unsigned int CIR;
    volatile unsigned int AHB1RSTR;
    volatile unsigned int AHB2RSTR;
    volatile unsigned int AHB3RSTR;
    unsigned int RESERVED0;
    volatile unsigned int APB1RSTR;
    volatile unsigned int APB2RSTR;
    unsigned int RESERVED1[2];
    volatile unsigned int AHB1ENR;
} RCC_TypeDef;

#endif
