################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./DSP2803x_CodeStartBranch.obj" \
"./DSP2803x_CpuTimers.obj" \
"./DSP2803x_DefaultIsr.obj" \
"./DSP2803x_EPwm.obj" \
"./DSP2803x_GlobalVariableDefs.obj" \
"./DSP2803x_PieCtrl.obj" \
"./DSP2803x_PieVect.obj" \
"./DSP2803x_SysCtrl.obj" \
"./DSP2803x_usDelay.obj" \
"./Example_2803xEPwmUpDownAQ.obj" \
"C:/Beuth/EPE-MES/02_Software/01_c2000/DSP2803x_common/cmd/28035_RAM_lnk.cmd" \
"C:/Beuth/EPE-MES/02_Software/01_c2000/DSP2803x_headers/cmd/DSP2803x_Headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-l"rts2800_ml.lib" \
-l"C:\Beuth\EPE-MES\04_Simulation\ASM\mathworks_libs\*" \
-l"IQmath.lib" \

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
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
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
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
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
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
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
EXE_OUTPUTS += \
Example_2803xEPwmUpDownAQ.out \

EXE_OUTPUTS__QUOTED += \
"Example_2803xEPwmUpDownAQ.out" \


# All Target
all: Example_2803xEPwmUpDownAQ.out

# Tool invocations
Example_2803xEPwmUpDownAQ.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --issue_remarks --output_all_syms --cdebug_asm_data -z -m"Example_2803xEPwmUpDownAQ.map" --stack_size=0x380 --warn_sections -i"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/lib" -i"C:/Beuth/EPE-MES/04_Simulation/ASM/matlab_libs" -i"C:/Beuth/EPE-MES/04_Simulation/ASM/mathworks_c_src" -i"C:/Beuth/EPE-MES/04_Simulation/ASM/simulink_libs" -i"C:/Beuth/EPE-MES/04_Simulation/ASM/Strommodel_grt_rtw" -i"C:/Beuth/EPE-MES/04_Simulation/ASM/Stromsollwerte_grt_rtw" -i"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/include" -i"C:/Beuth/EPE-MES/02_Software/01_c2000/DSP2803x_examples_ccsv5/epwm_updown_aq" -i"C:/Beuth/EPE-MES/02_Software/01_c2000/DSP2803x_headers/include" -i"C:/Beuth/libs/math/IQmath/v160/lib" --reread_libs --verbose_diagnostics --issue_remarks --xml_link_info="Example_2803xEPwmUpDownAQ_linkInfo.xml" --entry_point=code_start --rom_model -o "Example_2803xEPwmUpDownAQ.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "DSP2803x_CpuTimers.pp" "DSP2803x_DefaultIsr.pp" "DSP2803x_EPwm.pp" "DSP2803x_GlobalVariableDefs.pp" "DSP2803x_PieCtrl.pp" "DSP2803x_PieVect.pp" "DSP2803x_SysCtrl.pp" "Example_2803xEPwmUpDownAQ.pp" 
	-$(RM) "DSP2803x_CodeStartBranch.obj" "DSP2803x_CpuTimers.obj" "DSP2803x_DefaultIsr.obj" "DSP2803x_EPwm.obj" "DSP2803x_GlobalVariableDefs.obj" "DSP2803x_PieCtrl.obj" "DSP2803x_PieVect.obj" "DSP2803x_SysCtrl.obj" "DSP2803x_usDelay.obj" "Example_2803xEPwmUpDownAQ.obj" 
	-$(RM) "DSP2803x_CodeStartBranch.pp" "DSP2803x_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

