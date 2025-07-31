#ifndef __STM32F407xx_H
#define __STM32F407xx_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*
 * Definição do número de bits de prioridade usados pelo NVIC
 */
#define __NVIC_PRIO_BITS    4  // STM32F407 usa 4 bits para prioridade

/*
 * Enumeração dos vetores de interrupção do Cortex-M4 + periféricos STM32F407
 */
typedef enum {
  /* Cortex-M4 Processors Exceptions Numbers */
  NonMaskableInt_IRQn         = -14,
  MemoryManagement_IRQn       = -12,
  BusFault_IRQn               = -11,
  UsageFault_IRQn             = -10,
  SVCall_IRQn                 = -5,
  DebugMonitor_IRQn           = -4,
  PendSV_IRQn                 = -2,
  SysTick_IRQn                = -1,

  /* STM32F407 specific Interrupt Numbers (exemplos principais) */
  WWDG_IRQn                   = 0,
  PVD_IRQn                    = 1,
  TAMP_STAMP_IRQn            = 2,
  RTC_WKUP_IRQn              = 3,
  FLASH_IRQn                 = 4,
  RCC_IRQn                   = 5,
  EXTI0_IRQn                 = 6,
  EXTI1_IRQn                 = 7,
  EXTI2_IRQn                 = 8,
  EXTI3_IRQn                 = 9,
  EXTI4_IRQn                 = 10,
  DMA1_Stream0_IRQn          = 11,
  DMA1_Stream1_IRQn          = 12,
  DMA1_Stream2_IRQn          = 13,
  DMA1_Stream3_IRQn          = 14,
  DMA1_Stream4_IRQn          = 15,
  DMA1_Stream5_IRQn          = 16,
  DMA1_Stream6_IRQn          = 17,
  ADC_IRQn                   = 18,
  // ...
  TIM2_IRQn                  = 28,
  // Adicione mais se necessário
} IRQn_Type;

/*
 * Incluir o core CMSIS
 */
#include "core_cm4.h"

#ifdef __cplusplus
}
#endif

#endif /* __STM32F407xx_H */
