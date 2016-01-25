################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_UPPER_SRCS += \
../F28035_RAM_HVACI_Sensored.CMD 

LIB_SRCS += \
C:/ti/controlSUITE/libs/math/IQmath/v15c/lib/IQmath.lib 

C_SRCS += \
../DSP2803x_ECan.c \
C:/ti/controlSUITE/development_kits/~SupportFiles/source/DSP2803x_GlobalVariableDefs.c \
../HVACI_Sensored-DevInit_F2803x.c \
../HVACI_Sensored.c 

ASM_SRCS += \
../DLOG4CHC.asm \
../DSP2803x_usDelay.asm 

CMD_SRCS += \
C:/ti/controlSUITE/device_support/f2803x/v122/DSP2803x_headers/cmd/DSP2803x_Headers_nonBIOS.cmd 

ASM_DEPS += \
./DLOG4CHC.pp \
./DSP2803x_usDelay.pp 

OBJS += \
./DLOG4CHC.obj \
./DSP2803x_ECan.obj \
./DSP2803x_GlobalVariableDefs.obj \
./DSP2803x_usDelay.obj \
./HVACI_Sensored-DevInit_F2803x.obj \
./HVACI_Sensored.obj 

C_DEPS += \
./DSP2803x_ECan.pp \
./DSP2803x_GlobalVariableDefs.pp \
./HVACI_Sensored-DevInit_F2803x.pp \
./HVACI_Sensored.pp 

OBJS__QTD += \
".\DLOG4CHC.obj" \
".\DSP2803x_ECan.obj" \
".\DSP2803x_GlobalVariableDefs.obj" \
".\DSP2803x_usDelay.obj" \
".\HVACI_Sensored-DevInit_F2803x.obj" \
".\HVACI_Sensored.obj" 

ASM_DEPS__QTD += \
".\DLOG4CHC.pp" \
".\DSP2803x_usDelay.pp" 

C_DEPS__QTD += \
".\DSP2803x_ECan.pp" \
".\DSP2803x_GlobalVariableDefs.pp" \
".\HVACI_Sensored-DevInit_F2803x.pp" \
".\HVACI_Sensored.pp" 

ASM_SRCS_QUOTED += \
"../DLOG4CHC.asm" \
"../DSP2803x_usDelay.asm" 

C_SRCS_QUOTED += \
"../DSP2803x_ECan.c" \
"C:/ti/controlSUITE/development_kits/~SupportFiles/source/DSP2803x_GlobalVariableDefs.c" \
"../HVACI_Sensored-DevInit_F2803x.c" \
"../HVACI_Sensored.c" 


