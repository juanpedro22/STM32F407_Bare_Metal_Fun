/* linker.ld */

ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1024K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 128K /* pode ajustar para 192K se quiser usar CCM RAM também */
}

/* Símbolos necessários */
_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
  /* Vetor de interrupções no início da FLASH */
  .isr_vector :
  {
    KEEP(*(.isr_vector))
  } > FLASH

  /* Código */
  .text :
  {
    *(.text)           /* código */
    *(.text*)          /* outras seções .text */
    *(.rodata)         /* dados somente leitura */
    *(.rodata*)        /* constantes */
    KEEP(*(.init))
    KEEP(*(.fini))
  } > FLASH

  /* Dados inicializados - copiados da flash para a RAM */
  .data : AT(ADDR(.text) + SIZEOF(.text))
  {
    _sidata = LOADADDR(.data); /* início dos dados na FLASH */
    _sdata = .;                /* início dos dados na RAM */
    *(.data)
    *(.data*)
    _edata = .;                /* fim dos dados */
  } > RAM

  /* Dados não inicializados (zerados no startup) */
  .bss :
  {
    _sbss = .;
    *(.bss)
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM

  /* Stack pointer (cresce para baixo) */
  ._user_stack :
  {
    . = ALIGN(8);
    _stack_top = .;
  } > RAM
}
