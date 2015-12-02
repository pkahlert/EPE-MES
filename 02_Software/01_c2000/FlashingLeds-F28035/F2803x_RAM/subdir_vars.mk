################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
C:/Beuth/device_support/f2803x/v121/DSP2803x_headers/cmd/DSP2803x_Headers_nonBIOS.cmd 

CMD_UPPER_SRCS += \
../F28035_RAM_FlashingLeds.CMD 

ASM_SRCS += \
C:/Beuth/device_support/f2803x/v121/DSP2803x_common/source/DSP2803x_CodeStartBranch.asm \
../FlashingLeds-CLA.asm 

C_SRCS += \
C:/Beuth/device_support/f2803x/v121/DSP2803x_headers/source/DSP2803x_GlobalVariableDefs.c \
../FlashingLeds-DevInit_F2803x.c \
../FlashingLeds-Main.c \
C:/Beuth/development_kits/~SupportFiles/source/SciCommsGui.c 

OBJS += \
./DSP2803x_CodeStartBranch.obj \
./DSP2803x_GlobalVariableDefs.obj \
./FlashingLeds-CLA.obj \
./FlashingLeds-DevInit_F2803x.obj \
./FlashingLeds-Main.obj \
./SciCommsGui.obj 

ASM_DEPS += \
./DSP2803x_CodeStartBranch.pp \
./FlashingLeds-CLA.pp 

C_DEPS += \
./DSP2803x_GlobalVariableDefs.pp \
./FlashingLeds-DevInit_F2803x.pp \
./FlashingLeds-Main.pp \
./SciCommsGui.pp 

C_DEPS__QUOTED += \
"DSP2803x_GlobalVariableDefs.pp" \
"FlashingLeds-DevInit_F2803x.pp" \
"FlashingLeds-Main.pp" \
"SciCommsGui.pp" 

OBJS__QUOTED += \
"DSP2803x_CodeStartBranch.obj" \
"DSP2803x_GlobalVariableDefs.obj" \
"FlashingLeds-CLA.obj" \
"FlashingLeds-DevInit_F2803x.obj" \
"FlashingLeds-Main.obj" \
"SciCommsGui.obj" 

ASM_DEPS__QUOTED += \
"DSP2803x_CodeStartBranch.pp" \
"FlashingLeds-CLA.pp" 

ASM_SRCS__QUOTED += \
"C:/Beuth/device_support/f2803x/v121/DSP2803x_common/source/DSP2803x_CodeStartBranch.asm" \
"../FlashingLeds-CLA.asm" 

C_SRCS__QUOTED += \
"C:/Beuth/device_support/f2803x/v121/DSP2803x_headers/source/DSP2803x_GlobalVariableDefs.c" \
"../FlashingLeds-DevInit_F2803x.c" \
"../FlashingLeds-Main.c" \
"C:/Beuth/development_kits/~SupportFiles/source/SciCommsGui.c" 


