################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SERVICE/US/USvehicle_Program.c 

OBJS += \
./Core/Src/SERVICE/US/USvehicle_Program.o 

C_DEPS += \
./Core/Src/SERVICE/US/USvehicle_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SERVICE/US/%.o Core/Src/SERVICE/US/%.su Core/Src/SERVICE/US/%.cyclo: ../Core/Src/SERVICE/US/%.c Core/Src/SERVICE/US/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-SERVICE-2f-US

clean-Core-2f-Src-2f-SERVICE-2f-US:
	-$(RM) ./Core/Src/SERVICE/US/USvehicle_Program.cyclo ./Core/Src/SERVICE/US/USvehicle_Program.d ./Core/Src/SERVICE/US/USvehicle_Program.o ./Core/Src/SERVICE/US/USvehicle_Program.su

.PHONY: clean-Core-2f-Src-2f-SERVICE-2f-US

