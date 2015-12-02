################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
DSP2803x_CodeStartBranch.obj: C:/Beuth/device_support/f2803x/v121/DSP2803x_common/source/DSP2803x_CodeStartBranch.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/Beuth/development_kits/~SupportFiles/F2803x_headers" -g --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2803x_CodeStartBranch.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2803x_GlobalVariableDefs.obj: C:/Beuth/device_support/f2803x/v121/DSP2803x_headers/source/DSP2803x_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/Beuth/development_kits/~SupportFiles/F2803x_headers" -g --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2803x_GlobalVariableDefs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

FlashingLeds-CLA.obj: ../FlashingLeds-CLA.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/Beuth/development_kits/~SupportFiles/F2803x_headers" -g --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --diag_warning=225 --preproc_with_compile --preproc_dependency="FlashingLeds-CLA.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

FlashingLeds-DevInit_F2803x.obj: ../FlashingLeds-DevInit_F2803x.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/Beuth/development_kits/~SupportFiles/F2803x_headers" -g --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --diag_warning=225 --preproc_with_compile --preproc_dependency="FlashingLeds-DevInit_F2803x.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

FlashingLeds-Main.obj: ../FlashingLeds-Main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/Beuth/development_kits/~SupportFiles/F2803x_headers" -g --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --diag_warning=225 --preproc_with_compile --preproc_dependency="FlashingLeds-Main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

SciCommsGui.obj: C:/Beuth/development_kits/~SupportFiles/source/SciCommsGui.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_headers/include" --include_path="C:/Beuth/device_support/f2803x/v121/DSP2803x_common/include" --include_path="C:/Beuth/development_kits/~SupportFiles/F2803x_headers" -g --define="_DEBUG" --define="LARGE_MODEL" --define="FLASH" --diag_warning=225 --preproc_with_compile --preproc_dependency="SciCommsGui.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


