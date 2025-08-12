# 🚀 STM32F407 Bare-Metal Fun

This roadmap outlines a set of practical and fun features to build on top of a fully bare-metal STM32F407VG project — no HAL, no C++ classes, no bloated frameworks. Just pure registers, bitwise operations, and blinking LEDs.

## ⚙️ Build and Flash on STM32F407 (Bare-metal)

make        # Build
make bin    # Generate firmware.bin
make hex    # Generate firmware.hex
make flash  # Flash to the board (OpenOCD + ST-LINK)
make clean  # Remove .o, .elf, .bin, .hex, .map, and other temporary files

---

## ✅  Core Setup
- [x] ✅ Minimal project with Makefile, linker script, and startup code
- [x] ✅ LED blinking using SysTick-based delay
- [x] ✅ 16x2 LCD over I2C (PCF8574T) working with custom driver
- [x] ✅ Basic GPIO control (output, toggling)

---

## 🛰️  Communication Playground
- [ ] ✅ UART printf (USART2 to USB)
- [ ] ☐ UART receive with interrupts and circular buffer
- [ ] ☐ UART + DMA combo (non-blocking transfers)
- [ ] ☐ Serial menu for fun interaction (change LED speed, show time, etc.)

---

## 🔍  Reading the World
- [ ] ☐ ADC read from potentiometer
- [ ] ☐ I2C temperature sensor (e.g., LM75 or BMP180)
- [ ] ☐ External EEPROM over I2C (store boot counters, user config)
- [ ] ☐ HC-SR04 distance sensor with input capture

---

## ⏱️ Timer Tricks
- [ ] ☐ PWM LED brightness control
- [ ] ☐ Servo motor via PWM (angle control)
- [ ] ☐ Output Compare to schedule blinking events
- [ ] ☐ Rotary encoder support with TIMx in encoder mode

---

## 🎛️ UI & Interaction
- [ ] ☐ LCD menu navigation using buttons
- [ ] ☐ Buzzer tone generator using PWM
- [ ] ☐ LED color selector via potentiometer + LCD
- [ ] ☐ Debounced button logic with interrupts

---

## 📈  Debug & Profiling
- [ ] ✅ Display runtime diagnostics on LCD
- [ ] ☐ Toggle GPIO for scope-based performance measurement
- [ ] ☐ Print stack usage via linker map or estimation
- [ ] ☐ UART dump of memory regions or registers

---

## 🧨 Advanced Toys
- [ ] ☐ Watchdog timer experiment (IWDG)
- [ ] ☐ Basic bootloader switchable via button
- [ ] ☐ Low-power modes (stop/sleep) with wakeup pin
- [ ] ☐ Light encryption (XOR or software AES)



---

🎯 **Goal:** Build cool things from scratch, explore hardware capabilities, and push your STM32F407 to its limits — all without relying on HAL or RTOS. Just you, the datasheet, and the bare metal.



## Project Board

![alt text](image.png)