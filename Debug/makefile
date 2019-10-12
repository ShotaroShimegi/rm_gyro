################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/System/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
rm_gyro.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
rm_gyro.list \

OBJCOPY_HEX += \
rm_gyro.hex \


# All Target
all: rm_gyro.elf secondary-outputs

# Tool invocations
rm_gyro.elf: $(OBJS) $(USER_OBJS) C:\Users\shimegi\STM32CubeIDE\workspace_1.0.0\rm_gyro\STM32F303K8TX_FLASH.ld
	arm-none-eabi-gcc -o "rm_gyro.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\shimegi\STM32CubeIDE\workspace_1.0.0\rm_gyro\STM32F303K8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="rm_gyro.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

rm_gyro.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "rm_gyro.list"
	@echo 'Finished building: $@'
	@echo ' '

rm_gyro.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "rm_gyro.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
