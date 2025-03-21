################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/1/git/My-bldc/CH32V203C8T6/project/user/ch32v20x_it.c \
F:/1/git/My-bldc/CH32V203C8T6/project/user/main.c \
F:/1/git/My-bldc/CH32V203C8T6/project/user/system_ch32v20x.c 

OBJS += \
./user/ch32v20x_it.o \
./user/main.o \
./user/system_ch32v20x.o 

C_DEPS += \
./user/ch32v20x_it.d \
./user/main.d \
./user/system_ch32v20x.d 


# Each subdirectory must supply rules for building sources it contributes
user/ch32v20x_it.o: F:/1/git/My-bldc/CH32V203C8T6/project/user/ch32v20x_it.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user/main.o: F:/1/git/My-bldc/CH32V203C8T6/project/user/main.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user/system_ch32v20x.o: F:/1/git/My-bldc/CH32V203C8T6/project/user/system_ch32v20x.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

