################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/Delay\ Driver/delay.c 

OBJS += \
./ECUAL/Delay\ Driver/delay.o 

C_DEPS += \
./ECUAL/Delay\ Driver/delay.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/Delay\ Driver/delay.o: ../ECUAL/Delay\ Driver/delay.c ECUAL/Delay\ Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Andrew Gam3a\egfwd\GPIO_Driver_Eclipse_WS\On_Demand_Traffic_Light_Control" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"ECUAL/Delay Driver/delay.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


