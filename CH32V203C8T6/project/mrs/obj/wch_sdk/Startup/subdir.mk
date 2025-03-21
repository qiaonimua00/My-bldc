################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Startup/startup_ch32v20x_D6.S 

OBJS += \
./wch_sdk/Startup/startup_ch32v20x_D6.o 

S_UPPER_DEPS += \
./wch_sdk/Startup/startup_ch32v20x_D6.d 


# Each subdirectory must supply rules for building sources it contributes
wch_sdk/Startup/startup_ch32v20x_D6.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Startup/startup_ch32v20x_D6.S
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -x assembler-with-cpp -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

