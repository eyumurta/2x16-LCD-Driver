################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/LCD_Driver/Src/LCD.c 

OBJS += \
./Core/LCD_Driver/Src/LCD.o 

C_DEPS += \
./Core/LCD_Driver/Src/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
Core/LCD_Driver/Src/%.o Core/LCD_Driver/Src/%.su Core/LCD_Driver/Src/%.cyclo: ../Core/LCD_Driver/Src/%.c Core/LCD_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Muhammed/STM32CubeIDE/workspace_1.8.0/LCD_Driver/Core/LCD_Driver/Inc" -I"C:/Users/Muhammed/STM32CubeIDE/workspace_1.8.0/LCD_Driver/Core/LCD_Driver/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-LCD_Driver-2f-Src

clean-Core-2f-LCD_Driver-2f-Src:
	-$(RM) ./Core/LCD_Driver/Src/LCD.cyclo ./Core/LCD_Driver/Src/LCD.d ./Core/LCD_Driver/Src/LCD.o ./Core/LCD_Driver/Src/LCD.su

.PHONY: clean-Core-2f-LCD_Driver-2f-Src

