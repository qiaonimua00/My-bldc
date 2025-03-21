################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Core/core_riscv.c 

OBJS += \
./wch_sdk/Core/core_riscv.o 

C_DEPS += \
./wch_sdk/Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
wch_sdk/Core/core_riscv.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Core/core_riscv.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

