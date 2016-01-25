################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
DLOG4CHC.obj: ../DLOG4CHC.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/include" --include_path="D:/MA_Project/TI_CCS/xdais_7_10_00_06/packages/ti/xdais" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/ti/controlSUITE/libs/math/IQmath/v15b/include" --include_path="C:/ti/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/math_blocks/fixed_v1.1" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v1.2" --quiet --diag_warning=225 --large_memory_model --preproc_with_compile --preproc_dependency="DLOG4CHC.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2803x_ECan.obj: ../DSP2803x_ECan.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/include" --include_path="D:/MA_Project/TI_CCS/xdais_7_10_00_06/packages/ti/xdais" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/ti/controlSUITE/libs/math/IQmath/v15b/include" --include_path="C:/ti/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/math_blocks/fixed_v1.1" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v1.2" --quiet --diag_warning=225 --large_memory_model --preproc_with_compile --preproc_dependency="DSP2803x_ECan.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2803x_GlobalVariableDefs.obj: C:/ti/controlSUITE/development_kits/~SupportFiles/source/DSP2803x_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/include" --include_path="D:/MA_Project/TI_CCS/xdais_7_10_00_06/packages/ti/xdais" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/ti/controlSUITE/libs/math/IQmath/v15b/include" --include_path="C:/ti/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/math_blocks/fixed_v1.1" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v1.2" --quiet --diag_warning=225 --large_memory_model --preproc_with_compile --preproc_dependency="DSP2803x_GlobalVariableDefs.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2803x_usDelay.obj: ../DSP2803x_usDelay.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/include" --include_path="D:/MA_Project/TI_CCS/xdais_7_10_00_06/packages/ti/xdais" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/ti/controlSUITE/libs/math/IQmath/v15b/include" --include_path="C:/ti/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/math_blocks/fixed_v1.1" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v1.2" --quiet --diag_warning=225 --large_memory_model --preproc_with_compile --preproc_dependency="DSP2803x_usDelay.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

HVACI_Sensored-DevInit_F2803x.obj: ../HVACI_Sensored-DevInit_F2803x.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/include" --include_path="D:/MA_Project/TI_CCS/xdais_7_10_00_06/packages/ti/xdais" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/ti/controlSUITE/libs/math/IQmath/v15b/include" --include_path="C:/ti/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/math_blocks/fixed_v1.1" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v1.2" --quiet --diag_warning=225 --large_memory_model --preproc_with_compile --preproc_dependency="HVACI_Sensored-DevInit_F2803x.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

HVACI_Sensored.obj: ../HVACI_Sensored.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="D:/MA_Project/TI_CCS/ccsv4/tools/compiler/c2000/include" --include_path="D:/MA_Project/TI_CCS/xdais_7_10_00_06/packages/ti/xdais" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/ti/controlSUITE/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/ti/controlSUITE/libs/math/IQmath/v15b/include" --include_path="C:/ti/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/math_blocks/fixed_v1.1" --include_path="C:/ti/controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v1.2" --quiet --diag_warning=225 --large_memory_model --preproc_with_compile --preproc_dependency="HVACI_Sensored.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


