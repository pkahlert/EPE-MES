################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)
CG_TOOL_ROOT := D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"C:/ti/controlSUITE/device_support/f2803x/v122/DSP2803x_headers/cmd/DSP2803x_Headers_nonBIOS.cmd" \
"./HVACI_Sensored.obj" \
"./HVACI_Sensored-DevInit_F2803x.obj" \
"./DSP2803x_usDelay.obj" \
"./DSP2803x_GlobalVariableDefs.obj" \
"./DSP2803x_ECan.obj" \
"./DLOG4CHC.obj" \
-l"rts2800_ml.lib" \
"../F28035_RAM_HVACI_Sensored.CMD" \
"C:/ti/controlSUITE/libs/math/IQmath/v15c/lib/IQmath.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: HVACI_Sensored.out

# Tool invocations
HVACI_Sensored.out: $(OBJS) $(CMD_SRCS) $(CMD_UPPER_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --diag_warning=225 --large_memory_model -z -m"HVACI_Sensored.map" --stack_size=0x380 --warn_sections -i"D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/lib" -i"D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/include" -i"C:/ti/controlSUITE/development_kits/HVMotorCtrl+PfcKit_v1.7/HVACI_Sensored" --reread_libs --rom_model -o "HVACI_Sensored.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C2000_EXECUTABLE_OUTPUTS__QTD) "HVACI_Sensored.out"
	-$(RM) ".\DLOG4CHC.obj" ".\DSP2803x_ECan.obj" ".\DSP2803x_GlobalVariableDefs.obj" ".\DSP2803x_usDelay.obj" ".\HVACI_Sensored-DevInit_F2803x.obj" ".\HVACI_Sensored.obj" 
	-$(RM) ".\DLOG4CHC.pp" ".\DSP2803x_usDelay.pp" 
	-$(RM) ".\DSP2803x_ECan.pp" ".\DSP2803x_GlobalVariableDefs.pp" ".\HVACI_Sensored-DevInit_F2803x.pp" ".\HVACI_Sensored.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
