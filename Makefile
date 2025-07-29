CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
CFLAGS=-mcpu=cortex-m4 -mthumb -Wall -g -O0
LDFLAGS=-Tlinker.ld -nostartfiles
SRC=src/main.c src/startup.s
INCLUDES=-Iinc

ELF=main.elf
HEX=main.hex

STLINK="C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility/ST-LINK_CLI.exe"

all: $(HEX)

$(ELF): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(LDFLAGS) -o $@

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

flash: $(HEX)
	$(STLINK) -c SWD -P $(HEX) 0x8000000 -V -Rst

clean:
	del /Q *.elf *.hex *.o
