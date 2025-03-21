################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BLDC_c/control.c \
../BLDC_c/led.c \
../BLDC_c/opma.c \
../BLDC_c/pwm_output.c \
../BLDC_c/usart.c 

OBJS += \
./BLDC_c/control.o \
./BLDC_c/led.o \
./BLDC_c/opma.o \
./BLDC_c/pwm_output.o \
./BLDC_c/usart.o 

C_DEPS += \
./BLDC_c/control.d \
./BLDC_c/led.d \
./BLDC_c/opma.d \
./BLDC_c/pwm_output.d \
./BLDC_c/usart.d 


# Each subdirectory must supply rules for building sources it contributes
BLDC_c/%.o: ../BLDC_c/%.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

