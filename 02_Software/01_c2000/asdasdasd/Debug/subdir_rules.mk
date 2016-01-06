################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --include_path="C:/Beuth/ti_motorware/ccs/ccsv6/tools/compiler/ti-cgt-c2000_15.9.0.STS/include" -g --display_error_number --diag_wrap=off --diag_warning=225 --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


