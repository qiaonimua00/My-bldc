################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_adc.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_bkp.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_can.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_crc.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_dbgmcu.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_dma.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_exti.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_flash.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_gpio.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_i2c.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_iwdg.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_misc.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_opa.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_pwr.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_rcc.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_rtc.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_spi.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_tim.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_usart.c \
F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_wwdg.c 

OBJS += \
./wch_sdk/Peripheral/src/ch32v20x_adc.o \
./wch_sdk/Peripheral/src/ch32v20x_bkp.o \
./wch_sdk/Peripheral/src/ch32v20x_can.o \
./wch_sdk/Peripheral/src/ch32v20x_crc.o \
./wch_sdk/Peripheral/src/ch32v20x_dbgmcu.o \
./wch_sdk/Peripheral/src/ch32v20x_dma.o \
./wch_sdk/Peripheral/src/ch32v20x_exti.o \
./wch_sdk/Peripheral/src/ch32v20x_flash.o \
./wch_sdk/Peripheral/src/ch32v20x_gpio.o \
./wch_sdk/Peripheral/src/ch32v20x_i2c.o \
./wch_sdk/Peripheral/src/ch32v20x_iwdg.o \
./wch_sdk/Peripheral/src/ch32v20x_misc.o \
./wch_sdk/Peripheral/src/ch32v20x_opa.o \
./wch_sdk/Peripheral/src/ch32v20x_pwr.o \
./wch_sdk/Peripheral/src/ch32v20x_rcc.o \
./wch_sdk/Peripheral/src/ch32v20x_rtc.o \
./wch_sdk/Peripheral/src/ch32v20x_spi.o \
./wch_sdk/Peripheral/src/ch32v20x_tim.o \
./wch_sdk/Peripheral/src/ch32v20x_usart.o \
./wch_sdk/Peripheral/src/ch32v20x_wwdg.o 

C_DEPS += \
./wch_sdk/Peripheral/src/ch32v20x_adc.d \
./wch_sdk/Peripheral/src/ch32v20x_bkp.d \
./wch_sdk/Peripheral/src/ch32v20x_can.d \
./wch_sdk/Peripheral/src/ch32v20x_crc.d \
./wch_sdk/Peripheral/src/ch32v20x_dbgmcu.d \
./wch_sdk/Peripheral/src/ch32v20x_dma.d \
./wch_sdk/Peripheral/src/ch32v20x_exti.d \
./wch_sdk/Peripheral/src/ch32v20x_flash.d \
./wch_sdk/Peripheral/src/ch32v20x_gpio.d \
./wch_sdk/Peripheral/src/ch32v20x_i2c.d \
./wch_sdk/Peripheral/src/ch32v20x_iwdg.d \
./wch_sdk/Peripheral/src/ch32v20x_misc.d \
./wch_sdk/Peripheral/src/ch32v20x_opa.d \
./wch_sdk/Peripheral/src/ch32v20x_pwr.d \
./wch_sdk/Peripheral/src/ch32v20x_rcc.d \
./wch_sdk/Peripheral/src/ch32v20x_rtc.d \
./wch_sdk/Peripheral/src/ch32v20x_spi.d \
./wch_sdk/Peripheral/src/ch32v20x_tim.d \
./wch_sdk/Peripheral/src/ch32v20x_usart.d \
./wch_sdk/Peripheral/src/ch32v20x_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
wch_sdk/Peripheral/src/ch32v20x_adc.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_adc.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_bkp.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_bkp.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_can.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_can.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_crc.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_crc.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_dbgmcu.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_dbgmcu.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_dma.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_dma.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_exti.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_exti.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_flash.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_flash.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_gpio.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_gpio.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_i2c.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_i2c.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_iwdg.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_iwdg.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_misc.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_misc.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_opa.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_opa.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_pwr.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_pwr.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_rcc.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_rcc.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_rtc.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_rtc.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_spi.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_spi.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_tim.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_tim.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_usart.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_usart.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
wch_sdk/Peripheral/src/ch32v20x_wwdg.o: F:/1/git/My-bldc/CH32V203C8T6/wch_sdk/Peripheral/src/ch32v20x_wwdg.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\1\git\My-bldc\CH32V203C8T6\project\user" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Core" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Debug" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Ld" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\inc" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Peripheral\src" -I"F:\1\git\My-bldc\CH32V203C8T6\wch_sdk\Startup" -I"F:\1\git\My-bldc\CH32V203C8T6\project\mrs\BLDC_h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

