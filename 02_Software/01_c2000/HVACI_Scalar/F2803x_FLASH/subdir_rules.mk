################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
DLOG4CHC.obj: ../DLOG4CHC.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -g --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/include" --include_path="C:/Beuth/ti_controlSUITE/device_support/f2803x/v125/DSP2803x_headers/include" --include_path="C:/Beuth/ti_controlSUITE/device_support/f2803x/v125/DSP2803x_common/include" --include_path="C:/Beuth/ti_controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/Beuth/ti_controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/Beuth/ti_controlSUITE/libs/app_libs/motor_control/math_blocks/v4.0" --include_path="C:/Beuth/ti_controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v2.0" --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --quiet --diag_warning=225 --preproc_with_compile --preproc_dependency="DLOG4CHC.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2803x_GlobalVariableDefs.obj: C:/TI/controlSUITE2_DMC\ Rev/device_support/f2803x/v122/DSP2803x_headers/source/DSP2803x_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -g --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/include" --include_path="C:/Beuth/ti_controlSUITE/device_support/f2803x/v125/DSP2803x_headers/include" --include_path="C:/Beuth/ti_controlSUITE/device_support/f2803x/v125/DSP2803x_common/include" --include_path="C:/Beuth/ti_controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/Beuth/ti_controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/Beuth/ti_controlSUITE/libs/app_libs/motor_control/math_blocks/v4.0" --include_path="C:/Beuth/ti_controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v2.0" --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --quiet --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2803x_GlobalVariableDefs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2803x_usDelay.obj: ../DSP2803x_usDelay.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -g --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/include" --include_path="C:/Beuth/ti_controlSUITE/device_support/f2803x/v125/DSP2803x_headers/include" --include_path="C:/Beuth/ti_controlSUITE/device_support/f2803x/v125/DSP2803x_common/include" --include_path="C:/Beuth/ti_controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/Beuth/ti_controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/Beuth/ti_controlSUITE/libs/app_libs/motor_control/math_blocks/v4.0" --include_path="C:/Beuth/ti_controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v2.0" --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --quiet --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2803x_usDelay.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

HVACI_Scalar-DevInit_F2803x.obj: ../HVACI_Scalar-DevInit_F2803x.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -g --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/include" --include_path="C:/Beuth/ti_controlSUITE/device_support/f2803x/v125/DSP2803x_headers/include" --include_path="C:/Beuth/ti_controlSUITE/device_support/f2803x/v125/DSP2803x_common/include" --include_path="C:/Beuth/ti_controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/Beuth/ti_controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/Beuth/ti_controlSUITE/libs/app_libs/motor_control/math_blocks/v4.0" --include_path="C:/Beuth/ti_controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v2.0" --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --quiet --diag_warning=225 --preproc_with_compile --preproc_dependency="HVACI_Scalar-DevInit_F2803x.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

HVACI_Scalar.obj: ../HVACI_Scalar.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -g --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/include" --include_path="C:/Beuth/ti_controlSUITE/device_support/f2803x/v125/DSP2803x_headers/include" --include_path="C:/Beuth/ti_controlSUITE/device_support/f2803x/v125/DSP2803x_common/include" --include_path="C:/Beuth/ti_controlSUITE/libs/math/IQmath/v15c/include" --include_path="C:/Beuth/ti_controlSUITE/development_kits/~SupportFiles/F2803x_headers" --include_path="C:/Beuth/ti_controlSUITE/libs/app_libs/motor_control/math_blocks/v4.0" --include_path="C:/Beuth/ti_controlSUITE/libs/app_libs/motor_control/drivers/f2803x_v2.0" --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --quiet --diag_warning=225 --preproc_with_compile --preproc_dependency="HVACI_Scalar.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


