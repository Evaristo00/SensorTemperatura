###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = STM32F103C6
COMPILER = "Keil for ARM"
TARGET = Debug
SHELL = C:\Windows\system32\cmd.exe

## Tools general options
ASMFLAGS=--cpu=cortex-m3 --thumb -g
CCFLAGS=--cpu=cortex-m3 --thumb -I.. -IC:/Keil_v5/ARM/CMSIS/Include -g
LDFLAGS=--scatter ../stm32f103x6.sct

## Processing Tools
CC=armcc.exe
LD=armlink.exe
ASM=armasm.exe
BIN2HEX=fromelf.exe
#  G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/Debug/Debug.elf: TOOL=LD
#     G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/Debug/main.o: TOOL=CC
#        G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/main.c
#     G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/Debug/system_stm32f1xx.o: TOOL=CC
#        G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/system_stm32f1xx.c
#     G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/Debug/startup_stm32f103.o: TOOL=ASM
#        G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/startup_stm32f103.s
#     G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/Debug/delay.o: TOOL=CC
#        G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/delay.c
#     G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/Debug/lcd.o: TOOL=CC
#        G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/lcd.c
#     G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/Debug/spi.o: TOOL=CC
#        G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/spi.c
#     G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/Debug/timer.o: TOOL=CC
#        G:/My Drive/Facultad/4to/Segundo Cuatrimestre/Taller 1/TP2/SensorTemp/SensorTemperatura/STM32F103C6/timer.c

# Build tree:
all:	Debug

Debug:	Debug.elf

Debug.elf:	main.o system_stm32f1xx.o startup_stm32f103.o delay.o lcd.o spi.o timer.o 
	$(LD)  $(LDFLAGS)  "main.o" "system_stm32f1xx.o" "startup_stm32f103.o" "delay.o" "lcd.o" "spi.o" "timer.o" --output "Debug.elf"

main.o:	../main.c 
	$(CC) $(CCFLAGS)  "../main.c" -c -o "main.o"

system_stm32f1xx.o:	../system_stm32f1xx.c 
	$(CC) $(CCFLAGS)  "../system_stm32f1xx.c" -c -o "system_stm32f1xx.o"

startup_stm32f103.o:	../startup_stm32f103.s 
	$(ASM) $(ASMFLAGS)  "../startup_stm32f103.s" -o "startup_stm32f103.o"

delay.o:	../delay.c 
	$(CC) $(CCFLAGS)  "../delay.c" -c -o "delay.o"

lcd.o:	../lcd.c 
	$(CC) $(CCFLAGS)  "../lcd.c" -c -o "lcd.o"

spi.o:	../spi.c 
	$(CC) $(CCFLAGS)  "../spi.c" -c -o "spi.o"

timer.o:	../timer.c 
	$(CC) $(CCFLAGS)  "../timer.c" -c -o "timer.o"

# tidy - delete all temporary files which are not involved in the target generation
tidy:

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.elf
	rm -rf main.o
	rm -rf system_stm32f1xx.o
	rm -rf startup_stm32f103.o
	rm -rf delay.o
	rm -rf lcd.o
	rm -rf spi.o
	rm -rf timer.o
