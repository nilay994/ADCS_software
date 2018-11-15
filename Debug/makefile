################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/nilay/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major

GEN_OPTS += /home/nilay/workspace_v8/tirtos_builds_MSP_EXP432P401R_debug_gcc/Debug/configPkg/compiler.opt
GEN_OPTS__FLAG := @"/home/nilay/workspace_v8/tirtos_builds_MSP_EXP432P401R_debug_gcc/Debug/configPkg/compiler.opt"
GEN_CMDS += /home/nilay/workspace_v8/tirtos_builds_MSP_EXP432P401R_debug_gcc/Debug/configPkg/linker.cmd
GEN_CMDS__FLAG := -Wl,-T"/home/nilay/workspace_v8/tirtos_builds_MSP_EXP432P401R_debug_gcc/Debug/configPkg/linker.cmd"

ORDERED_OBJS += \
"./ADCS_Board.o" \
"./ADCS_main.o" \
"./main_tirtos.o" \
"./libs/INA226.o" \
"./libs/MB85RS256A.o" \
"./libs/TMP100.o" \
"./libs/bmx_mag.o" \
"./libs/detumble_algo.o" \
"./ttc/PQ9_bus_engine.o" \
"./ttc/devices.o" \
"./ttc/fm.o" \
"./ttc/function_management_service.o" \
"./ttc/hal_functions.o" \
"./ttc/hal_subsystem.o" \
"./ttc/housekeeping.o" \
"./ttc/housekeeping_service.o" \
"./ttc/osal.o" \
"./ttc/packet_engine.o" \
"./ttc/packet_stats.o" \
"./ttc/packet_utilities.o" \
"./ttc/parameters.o" \
"./ttc/ping_service.o" \
"./ttc/pkt_pool.o" \
"./ttc/queue.o" \
"./ttc/satellite.o" \
"./ttc/subsystem.o" \
"./ttc/subsystem_pool.o" \
"./ttc/testing.o" \
"./ttc/verification_service.o" \
-Wl,-T"../MSP_EXP432P401R_TIRTOS.lds" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-l:"ti/display/lib/display.am4fg" \
-l:"ti/drivers/lib/drivers_msp432p401x.am4fg" \
-l:"ti/dpl/lib/dpl_msp432p401x.am4fg" \
-l:"ti/devices/msp432p4xx/driverlib/gcc/msp432p4xx_driverlib.a" \
-lgcc \
-lm \
-lnosys \
-lc \
-Wl,--end-group \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include libs/subdir_vars.mk
-include ttc/subdir_vars.mk
-include subdir_rules.mk
-include libs/subdir_rules.mk
-include ttc/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
ADCS_software.out \

EXE_OUTPUTS__QUOTED += \
"ADCS_software.out" \

BIN_OUTPUTS += \
ADCS_software.bin \

BIN_OUTPUTS__QUOTED += \
"ADCS_software.bin" \


# All Target
all:
	@$(MAKE) --no-print-directory pre-build
	@$(MAKE) --no-print-directory main-build

# Main-build Target
main-build: $(OBJS) $(LDS_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "ADCS_software.out"

dependents:
	-cd /home/nilay/workspace_v8/tirtos_builds_MSP_EXP432P401R_debug_gcc/Debug && $(MAKE) all

# Tool invocations
ADCS_software.out: $(OBJS) $(LDS_SRCS) $(GEN_CMDS) /home/nilay/workspace_v8/tirtos_builds_MSP_EXP432P401R_debug_gcc/Debug/libtirtos_builds_MSP_EXP432P401R_debug_gcc.a
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"/home/nilay/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc" -DDeviceFamily_MSP432P401x -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,-Map,"ADCS_software.map" -nostartfiles -static -Wl,--gc-sections -L"/home/nilay/ti/simplelink_msp432p4_sdk_2_10_00_14/source" -L"/home/nilay/ti/simplelink_msp432p4_sdk_2_10_00_14/kernel/tirtos/packages" -L"/home/nilay/ti/simplelink_msp432p4_sdk_2_10_00_14/kernel/tirtos/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard" -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nano.specs -o"ADCS_software.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

ADCS_software.bin: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: GNU Objcopy Utility'
	"/home/nilay/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-objcopy"  $(EXE_OUTPUTS__QUOTED) "ADCS_software.bin"
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "ADCS_Board.o" "ADCS_main.o" "main_tirtos.o" "libs/INA226.o" "libs/MB85RS256A.o" "libs/TMP100.o" "libs/bmx_mag.o" "libs/detumble_algo.o" "ttc/PQ9_bus_engine.o" "ttc/devices.o" "ttc/fm.o" "ttc/function_management_service.o" "ttc/hal_functions.o" "ttc/hal_subsystem.o" "ttc/housekeeping.o" "ttc/housekeeping_service.o" "ttc/osal.o" "ttc/packet_engine.o" "ttc/packet_stats.o" "ttc/packet_utilities.o" "ttc/parameters.o" "ttc/ping_service.o" "ttc/pkt_pool.o" "ttc/queue.o" "ttc/satellite.o" "ttc/subsystem.o" "ttc/subsystem_pool.o" "ttc/testing.o" "ttc/verification_service.o" 
	-$(RM) "ADCS_Board.d" "ADCS_main.d" "main_tirtos.d" "libs/INA226.d" "libs/MB85RS256A.d" "libs/TMP100.d" "libs/bmx_mag.d" "libs/detumble_algo.d" "ttc/PQ9_bus_engine.d" "ttc/devices.d" "ttc/fm.d" "ttc/function_management_service.d" "ttc/hal_functions.d" "ttc/hal_subsystem.d" "ttc/housekeeping.d" "ttc/housekeeping_service.d" "ttc/osal.d" "ttc/packet_engine.d" "ttc/packet_stats.d" "ttc/packet_utilities.d" "ttc/parameters.d" "ttc/ping_service.d" "ttc/pkt_pool.d" "ttc/queue.d" "ttc/satellite.d" "ttc/subsystem.d" "ttc/subsystem_pool.d" "ttc/testing.d" "ttc/verification_service.d" 
	-@echo 'Finished clean'
	-@echo ' '

pre-build:
	-@echo 'bin conversion'
	-"/home/nilay/ti/ccsv8/utils/tiobj2bin/tiobj2bin" "ADCS_software.out" "ADCS_software.bin" "/home/nilay/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/ofd2000" "/home/nilay/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/hex2000" "/home/nilay/ti/ccsv8/utils/tiobj2bin/mkhex4bin"
	-@echo ' '

post-build:
	-@echo 'bin conversion'
	-"/home/nilay/ti/ccsv8/utils/tiobj2bin/tiobj2bin" "ADCS_software.out" "ADCS_software.bin" "/home/nilay/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/ofd2000" "/home/nilay/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/hex2000" "/home/nilay/ti/ccsv8/utils/tiobj2bin/mkhex4bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/home/nilay/workspace_v8/tirtos_builds_MSP_EXP432P401R_debug_gcc/Debug/libtirtos_builds_MSP_EXP432P401R_debug_gcc.a:

-include ../makefile.targets

