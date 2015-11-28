################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/cmd/DSP2803x_Headers_nonBIOS.cmd 

CMD_UPPER_SRCS += \
../F28035_FLASH_ProjectName.CMD 

LIB_SRCS += \
C:/TI/controlSUITE/libs/math/IQmath/v15c/lib/IQmath.lib 

ASM_SRCS += \
C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/source/DSP2803x_CodeStartBranch.asm \
C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/source/DSP2803x_usDelay.asm \
../ProjectName-DPL-ISR.asm 

C_SRCS += \
C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/CNF/ADC_SOC_Cnf.c \
C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/source/DSP2803x_GlobalVariableDefs.c \
C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/CNF/PWM_1ch_Cnf.c \
../ProjectName-DevInit_F2803x.c \
../ProjectName-Main.c 

OBJS += \
./ADC_SOC_Cnf.obj \
./DSP2803x_CodeStartBranch.obj \
./DSP2803x_GlobalVariableDefs.obj \
./DSP2803x_usDelay.obj \
./PWM_1ch_Cnf.obj \
./ProjectName-CLA_Tasks.obj \
./ProjectName-DPL-ISR.obj \
./ProjectName-DevInit_F2803x.obj \
./ProjectName-Main.obj 

ASM_DEPS += \
./DSP2803x_CodeStartBranch.pp \
./DSP2803x_usDelay.pp \
./ProjectName-DPL-ISR.pp 

CLA_DEPS += \
./ProjectName-CLA_Tasks.pp 

C_DEPS += \
./ADC_SOC_Cnf.pp \
./DSP2803x_GlobalVariableDefs.pp \
./PWM_1ch_Cnf.pp \
./ProjectName-DevInit_F2803x.pp \
./ProjectName-Main.pp 

CLA_DEPS__QUOTED += \
"ProjectName-CLA_Tasks.pp" 

C_DEPS__QUOTED += \
"ADC_SOC_Cnf.pp" \
"DSP2803x_GlobalVariableDefs.pp" \
"PWM_1ch_Cnf.pp" \
"ProjectName-DevInit_F2803x.pp" \
"ProjectName-Main.pp" 

OBJS__QUOTED += \
"ADC_SOC_Cnf.obj" \
"DSP2803x_CodeStartBranch.obj" \
"DSP2803x_GlobalVariableDefs.obj" \
"DSP2803x_usDelay.obj" \
"PWM_1ch_Cnf.obj" \
"ProjectName-CLA_Tasks.obj" \
"ProjectName-DPL-ISR.obj" \
"ProjectName-DevInit_F2803x.obj" \
"ProjectName-Main.obj" 

ASM_DEPS__QUOTED += \
"DSP2803x_CodeStartBranch.pp" \
"DSP2803x_usDelay.pp" \
"ProjectName-DPL-ISR.pp" 

C_SRCS__QUOTED += \
"C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/CNF/ADC_SOC_Cnf.c" \
"C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_headers/source/DSP2803x_GlobalVariableDefs.c" \
"C:/TI/controlSUITE/libs/app_libs/digital_power/f2803x_v3.4/CNF/PWM_1ch_Cnf.c" \
"../ProjectName-DevInit_F2803x.c" \
"../ProjectName-Main.c" 

ASM_SRCS__QUOTED += \
"C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/source/DSP2803x_CodeStartBranch.asm" \
"C:/TI/controlSUITE/device_support/f2803x/v126/DSP2803x_common/source/DSP2803x_usDelay.asm" \
"../ProjectName-DPL-ISR.asm" 


