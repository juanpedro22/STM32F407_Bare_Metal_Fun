# Compilador e flags
CC = arm-none-eabi-gcc
AS = arm-none-eabi-gcc   # Usamos GCC para compilar startup.s com preprocessador
CFLAGS = -mcpu=cortex-m4 -mthumb -Wall -g -O0 -nostartfiles -DSTM32F407xx \
         -Iinc -Icmsis_core -Idevice

# Conversor e arquivos
OBJCOPY = arm-none-eabi-objcopy
HEX = main.hex

LDFLAGS = -T linker.ld

# Fontes e destino
SRCS_C = src/main.c src/timebase.c src/lcd_i2c.c device/system_stm32f4xx.c
SRCS_S = src/startup.s
TARGET = main.elf

STLINK = "C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\ST-LINK_CLI.exe"

# Regra padrão
all: $(TARGET)

# Linkagem
$(TARGET): $(SRCS_C) $(SRCS_S)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# Geração do HEX
$(HEX): $(TARGET)
	$(OBJCOPY) -O ihex $< $@

# Flash com ST-LINK_CLI
flash: $(HEX)
	$(STLINK) -c SWD -P $(HEX) 0x8000000 -V -Rst

# Limpeza
clean:
	del /Q *.elf *.hex *.o




