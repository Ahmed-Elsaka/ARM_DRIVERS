################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CALCULATOR_prog.c \
../src/DIO_prog.c \
../src/KPD_prog.c \
../src/LCD_prog.c \
../src/RCC_prog.c \
../src/_write.c \
../src/delay.c \
../src/main.c 

OBJS += \
./src/CALCULATOR_prog.o \
./src/DIO_prog.o \
./src/KPD_prog.o \
./src/LCD_prog.o \
./src/RCC_prog.o \
./src/_write.o \
./src/delay.o \
./src/main.o 

C_DEPS += \
./src/CALCULATOR_prog.d \
./src/DIO_prog.d \
./src/KPD_prog.d \
./src/LCD_prog.d \
./src/RCC_prog.d \
./src/_write.d \
./src/delay.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


