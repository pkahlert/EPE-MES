################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./ProjectName-Main.obj" \
"./ProjectName-DevInit_F2803x.obj" \
"./ProjectName-DPL-ISR.obj" \
"./ProjectName-CLA_Tasks.obj" \
"./PWM_1ch_Cnf.obj" \
"./DSP2803x_usDelay.obj" \
"./DSP2803x_GlobalVariableDefs.obj" \
"./DSP2803x_CodeStartBranch.obj" \
"./ADC_SOC_Cnf.obj" \
-l"libc.a" \
"C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/cmd/DSP2803x_Headers_nonBIOS.cmd" \
"../F28035_FLASH_ProjectName.CMD" \
"C:/TI/controlSUITE/libs/math/IQmath/v15c/lib/IQmath.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ProjectName.out

# Tool invocations
ProjectName.out: $(OBJS) $(CMD_SRCS) $(CMD_UPPER_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --define="_DEBUG" --define="FLASH" --define="LARGE_MODEL" --diag_warning=225 -z --stack_size=0x380 -m"ProjectName.map" --warn_sections -i"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/lib" -i"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/include" --reread_libs --rom_model -o "ProjectName.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C2000_EXECUTABLE_OUTPUTS__QUOTED) "ProjectName.out"
	-$(RM) "ProjectName-CLA_Tasks.pp" 
	-$(RM) "ADC_SOC_Cnf.pp" "DSP2803x_GlobalVariableDefs.pp" "PWM_1ch_Cnf.pp" "ProjectName-DevInit_F2803x.pp" "ProjectName-Main.pp" 
	-$(RM) "ADC_SOC_Cnf.obj" "DSP2803x_CodeStartBranch.obj" "DSP2803x_GlobalVariableDefs.obj" "DSP2803x_usDelay.obj" "PWM_1ch_Cnf.obj" "ProjectName-CLA_Tasks.obj" "ProjectName-DPL-ISR.obj" "ProjectName-DevInit_F2803x.obj" "ProjectName-Main.obj" 
	-$(RM) "DSP2803x_CodeStartBranch.pp" "DSP2803x_usDelay.pp" "ProjectName-DPL-ISR.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
