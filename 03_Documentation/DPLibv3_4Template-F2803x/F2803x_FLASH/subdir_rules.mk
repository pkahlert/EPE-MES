################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
ADC_SOC_Cnf.obj: C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/CNF/ADC_SOC_Cnf.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/C_macros" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/asm_macros" --include_path="C:/TI/controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/TI/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --define="_DEBUG" --define="FLASH" --define="LARGE_MODEL" --diag_warning=225 --preproc_with_compile --preproc_dependency="ADC_SOC_Cnf.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2803x_CodeStartBranch.obj: C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/source/DSP2803x_CodeStartBranch.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/C_macros" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/asm_macros" --include_path="C:/TI/controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/TI/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --define="_DEBUG" --define="FLASH" --define="LARGE_MODEL" --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2803x_CodeStartBranch.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2803x_GlobalVariableDefs.obj: C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/source/DSP2803x_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/C_macros" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/asm_macros" --include_path="C:/TI/controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/TI/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --define="_DEBUG" --define="FLASH" --define="LARGE_MODEL" --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2803x_GlobalVariableDefs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2803x_usDelay.obj: C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/source/DSP2803x_usDelay.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/C_macros" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/asm_macros" --include_path="C:/TI/controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/TI/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --define="_DEBUG" --define="FLASH" --define="LARGE_MODEL" --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2803x_usDelay.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

PWM_1ch_Cnf.obj: C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/CNF/PWM_1ch_Cnf.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/C_macros" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/asm_macros" --include_path="C:/TI/controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/TI/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --define="_DEBUG" --define="FLASH" --define="LARGE_MODEL" --diag_warning=225 --preproc_with_compile --preproc_dependency="PWM_1ch_Cnf.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ProjectName-CLA_Tasks.obj: ../ProjectName-CLA_Tasks.cla $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/C_macros" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/asm_macros" --include_path="C:/TI/controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/TI/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --define="_DEBUG" --define="FLASH" --define="LARGE_MODEL" --diag_warning=225 --preproc_with_compile --preproc_dependency="ProjectName-CLA_Tasks.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ProjectName-DPL-ISR.obj: ../ProjectName-DPL-ISR.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/C_macros" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/asm_macros" --include_path="C:/TI/controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/TI/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --define="_DEBUG" --define="FLASH" --define="LARGE_MODEL" --diag_warning=225 --preproc_with_compile --preproc_dependency="ProjectName-DPL-ISR.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ProjectName-DevInit_F2803x.obj: ../ProjectName-DevInit_F2803x.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/C_macros" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/asm_macros" --include_path="C:/TI/controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/TI/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --define="_DEBUG" --define="FLASH" --define="LARGE_MODEL" --diag_warning=225 --preproc_with_compile --preproc_dependency="ProjectName-DevInit_F2803x.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ProjectName-Main.obj: ../ProjectName-Main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -g --include_path="C:/CCS5/ccsv5/tools/compiler/c2000_6.1.1/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/C_macros" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/include" --include_path="C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/include" --include_path="C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/asm_macros" --include_path="C:/TI/controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/TI/controlSUITE/development_kits/~SupportFiles/F2803x_headers" --define="_DEBUG" --define="FLASH" --define="LARGE_MODEL" --diag_warning=225 --preproc_with_compile --preproc_dependency="ProjectName-Main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


