# Compilador e flags
CC = arm-none-eabi-gcc
AS = arm-none-eabi-gcc   # Usamos GCC para compilar startup.s com preprocessador
CFLAGS = -mcpu=cortex-m4 -mthumb -Wall -g -O0 -nostartfiles -DSTM32F407xx \
         -Iinc -Icmsis_core -Idevice

LDFLAGS = -T linker.ld

# Fontes e destino
SRCS_C = src/main.c src/timebase.c device/system_stm32f4xx.c
SRCS_S = src/startup.s
TARGET = main.elf

# Regra padrão
all: $(TARGET)

# Linkagem
$(TARGET): $(SRCS_C) $(SRCS_S)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# Limpeza
clean:
	rm -f $(TARGET) *.o src/*.o device/*.o
