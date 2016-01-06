################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Example_2802xEPwmUpDownAQ.obj: ../Example_2802xEPwmUpDownAQ.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/bin/cl2000" -v28 -ml -mt --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/include" --include_path="/device_support/f2803x/v125/DSP2803x_headers/include" --include_path="/development_kits/~SupportFiles/F2803x_headers" --include_path="/dev7ce_support/f2803x/v125/DSP2803x_common/include" --include_path="/packages/ti/xdais" --include_path="C:/Beuth/EPE-MES/libs/math/IQmath/v15c/include" --include_path="C:/Beuth/EPE-MES/02_Software/01_c2000/C2000_LaunchPad" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --output_all_syms --cdebug_asm_data --preproc_with_compile --preproc_dependency="Example_2802xEPwmUpDownAQ.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


