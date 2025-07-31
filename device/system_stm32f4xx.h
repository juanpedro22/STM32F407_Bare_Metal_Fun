#ifndef __SYSTEM_STM32F4XX_H
#define __SYSTEM_STM32F4XX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//!< Define padrão do clock (pode ser alterado pela aplicação)
extern uint32_t SystemCoreClock;

/**
 * @brief  Atualiza a variável SystemCoreClock com base nos registradores RCC.
 */
void SystemCoreClockUpdate(void);

/**
 * @brief  Inicializa o sistema (clock, FPU, etc.).
 *         É chamada no início do código (startup.s → main).
 */
void SystemInit(void);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_STM32F4XX_H */
