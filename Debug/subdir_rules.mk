################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/nilay/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DDeviceFamily_MSP432P401x -I"/home/nilay/workspace_v8/PQ9_bus_software/delfiPQ/ADCS" -I"/home/nilay/workspace_v8/PQ9_bus_software/delfiPQ/ADCS/HAL" -I"/home/nilay/workspace_v8/PQ9_bus_software/delfiPQ/HAL" -I"/home/nilay/workspace_v8/PQ9_bus_software/delfiPQ/OSAL" -I"/home/nilay/workspace_v8/PQ9_bus_software/delfiPQ" -I"/home/nilay/workspace_v8/PQ9_bus_software/core" -I"/home/nilay/workspace_v8/INA226" -I"/home/nilay/workspace_v8/TMP100" -I"/home/nilay/workspace_v8/MB85RS256A" -I"/home/nilay/workspace_v8/ADCS_software" -I"/home/nilay/ti/simplelink_msp432p4_sdk_2_10_00_14/source/third_party/CMSIS/Include" -I"/home/nilay/ti/simplelink_msp432p4_sdk_2_10_00_14/source/ti/posix/gcc" -I"/home/nilay/ti/simplelink_msp432p4_sdk_2_10_00_14/kernel/tirtos/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/include/newlib-nano" -I"/home/nilay/ti/simplelink_msp432p4_sdk_2_10_00_14/kernel/tirtos/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/include" -I"/home/nilay/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/arm-none-eabi/include" -I"/home/nilay/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/arm-none-eabi/include" -I"/home/nilay/workspace_v8/detumble/closed_loop" -I"/home/nilay/workspace_v8/detumble/detumble_algo_msp" -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  -std=c99 $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


