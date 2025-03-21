################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/1/关于竞赛/气垫船/代码/逐飞电调/CH32V203C8T6_BLDC_ESC/bldc_software/control.c \
F:/1/关于竞赛/气垫船/代码/逐飞电调/CH32V203C8T6_BLDC_ESC/bldc_software/motor.c 

OBJS += \
./bldc_software/control.o \
./bldc_software/motor.o 

C_DEPS += \
./bldc_software/control.d \
./bldc_software/motor.d 


# Each subdirectory must supply rules for building sources it contributes
bldc_software/control.o: F:/1/关于竞赛/气垫船/代码/逐飞电调/CH32V203C8T6_BLDC_ESC/bldc_software/control.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\addition_hardware" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\addition_software" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\bldc_config" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\bldc_hardware" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\bldc_software" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\project\user" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Core" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Debug" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Ld" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Peripheral" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Peripheral\inc" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Peripheral\src" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Startup" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
bldc_software/motor.o: F:/1/关于竞赛/气垫船/代码/逐飞电调/CH32V203C8T6_BLDC_ESC/bldc_software/motor.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\addition_hardware" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\addition_software" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\bldc_config" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\bldc_hardware" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\bldc_software" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\project\user" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Core" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Debug" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Ld" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Peripheral" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Peripheral\inc" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Peripheral\src" -isystem"F:\1\关于竞赛\气垫船\代码\逐飞电调\CH32V203C8T6_BLDC_ESC\wch_sdk\Startup" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

