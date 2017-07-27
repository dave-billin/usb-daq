#
# Copyright (c) 2011 Atmel Corporation. All rights reserved.
#
# \asf_license_start
#
# \page License
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. The name of Atmel may not be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# 4. This software may only be redistributed and used in connection with an
#    Atmel microcontroller product.
#
# THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
# EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# \asf_license_stop
#

# Verify that the path where the ATMEL Software Framework (ASF) source tree is located has been set
# in the top-level makefile
ifndef ASF_PATH
$(error ASF_PATH has not been set)
endif

# Path to top level ASF directory relative to this project directory.
#PRJ_PATH = $(ASF_PATH)

# Target CPU architecture: cortex-m3, cortex-m4
ARCH = cortex-m0plus

# Target part: none, sam3n4 or sam4l4aa
PART = samd11d14am

# Application target name. Given with suffix .a for library and .elf for a
# standalone application.
TARGET_FLASH = tmcc_mtd11_flash.elf
TARGET_SRAM = tmcc_mtd11_sram.elf

# List of C source files.
CSRCS = \
       $(ASF_PATH)/common/services/sleepmgr/samd/sleepmgr.c           \
       fw-arm/main.c                                                  \
       fw-arm/adc_driver.c                                            \
       mattairtech_mtd11/ui.c                                         \
       tmc_class/udi_tmc.c                                            \
       tmc_class/udi_tmc_desc.c                                       \
       $(ASF_PATH)/common/services/usb/udc/udc.c                      \
       $(ASF_PATH)/common/utils/interrupt/interrupt_sam_nvic.c        \
       mattairtech_mtd11/board_init.c                                 \
       $(ASF_PATH)/sam0/drivers/tcc/tcc.c                             \
       $(ASF_PATH)/sam0/drivers/tcc/tcc_callback.c                    \
       $(ASF_PATH)/sam0/drivers/extint/extint_callback.c              \
       $(ASF_PATH)/sam0/drivers/extint/extint_sam_d_r_h/extint.c      \
       $(ASF_PATH)/sam0/drivers/port/port.c                           \
       $(ASF_PATH)/sam0/drivers/system/clock/clock_samd09_d10_d11/clock.c \
       $(ASF_PATH)/sam0/drivers/system/clock/clock_samd09_d10_d11/gclk.c \
       $(ASF_PATH)/sam0/drivers/system/interrupt/system_interrupt.c   \
       $(ASF_PATH)/sam0/drivers/system/pinmux/pinmux.c                \
       $(ASF_PATH)/sam0/drivers/system/system.c                       \
       $(ASF_PATH)/sam0/drivers/usb/stack_interface/usb_device_udd.c  \
       $(ASF_PATH)/sam0/drivers/usb/stack_interface/usb_dual.c        \
       $(ASF_PATH)/sam0/drivers/usb/usb_sam_d_r/usb.c                 \
       $(ASF_PATH)/sam0/utils/cmsis/samd11/source/gcc/startup_samd11.c \
       $(ASF_PATH)/sam0/utils/cmsis/samd11/source/system_samd11.c     \
       $(ASF_PATH)/sam0/utils/syscalls/gcc/syscalls.c

# List of assembler source files.
ASSRCS = 

# List of include directories to search
INC_PATH = \
       $(CURDIR) \
       $(CURDIR)/mattairtech_mtd11                                    \
       $(CURDIR)/mattairtech_mtd11/board_config                       \
       $(CURDIR)/tmc_class                                            \
       $(CURDIR)/fw-arm                                               \
       $(ASF_PATH)/common/boards                                      \
       $(ASF_PATH)/common2/boards/user_board                          \
       $(ASF_PATH)/common/services/sleepmgr                           \
       $(ASF_PATH)/common/services/usb                                \
       $(ASF_PATH)/common/services/usb/udc                            \
       $(ASF_PATH)/common/utils                                       \
       $(ASF_PATH)/sam0/drivers/tcc                                   \
       $(ASF_PATH)/sam0/drivers/timer                                 \
       $(ASF_PATH)/sam0/drivers/extint                                \
       $(ASF_PATH)/sam0/drivers/extint/extint_sam_d_r_h               \
       $(ASF_PATH)/sam0/drivers/port                                  \
       $(ASF_PATH)/sam0/drivers/system                                \
       $(ASF_PATH)/sam0/drivers/system/clock                          \
       $(ASF_PATH)/sam0/drivers/system/clock/clock_samd09_d10_d11     \
       $(ASF_PATH)/sam0/drivers/system/interrupt                      \
       $(ASF_PATH)/sam0/drivers/system/interrupt/system_interrupt_samd10_d11 \
       $(ASF_PATH)/sam0/drivers/system/pinmux                         \
       $(ASF_PATH)/sam0/drivers/system/power                          \
       $(ASF_PATH)/sam0/drivers/system/power/power_sam_d_r_h          \
       $(ASF_PATH)/sam0/drivers/system/reset                          \
       $(ASF_PATH)/sam0/drivers/system/reset/reset_sam_d_r_h          \
       $(ASF_PATH)/sam0/drivers/usb                                   \
       $(ASF_PATH)/sam0/drivers/usb/stack_interface                   \
       $(ASF_PATH)/sam0/drivers/usb/usb_sam_d_r                       \
       $(ASF_PATH)/sam0/utils                                         \
       $(ASF_PATH)/sam0/utils/cmsis/samd11/include                    \
       $(ASF_PATH)/sam0/utils/cmsis/samd11/source                     \
       $(ASF_PATH)/sam0/utils/header_files                            \
       $(ASF_PATH)/sam0/utils/preprocessor                            \
       $(ASF_PATH)/thirdparty/CMSIS/Include                           \
       $(ASF_PATH)/thirdparty/CMSIS/Lib/GCC

# Additional search paths for libraries.
LIB_PATH =  \
       thirdparty/CMSIS/Lib/GCC

# List of libraries to use during linking.
LIBS =  \
       arm_cortexM0l_math

# Path relative to top level directory pointing to a linker script.
LINKER_SCRIPT_FLASH = $(ASF_PATH)/sam0/utils/linker_scripts/samd11/gcc/samd11d14am_flash.ld
LINKER_SCRIPT_SRAM  = $(ASF_PATH)/sam0/utils/linker_scripts/samd11/gcc/samd11d14am_sram.ld

# Path relative to top level directory pointing to a linker script.
DEBUG_SCRIPT_FLASH = mattairtech_mtd11/debug_scripts/gcc/mattairtech_mtd11_flash.gdb
DEBUG_SCRIPT_SRAM  = mattairtech_mtd11/debug_scripts/gcc/mattairtech_mtd11_sram.gdb

# Project type parameter: all, sram or flash
PROJECT_TYPE        = flash

# Additional options for debugging. By default the common Makefile.in will
# add -g3.
DBGFLAGS = 

# Application optimization used during compilation and linking:
# -O0, -O1, -O2, -O3 or -Os
OPTIMIZATION = -O1

# Extra flags to use when archiving.
ARFLAGS = 

# Extra flags to use when assembling.
ASFLAGS = 

# Extra flags to use when compiling.
CFLAGS = 

# Extra flags to use when preprocessing.
#
# Preprocessor symbol definitions
#   To add a definition use the format "-D name[=definition]".
#   To cancel a definition use the format "-U name".
#
# The most relevant symbols to define for the preprocessor are:
#   BOARD      Target board in use, see boards/board.h for a list.
#   EXT_BOARD  Optional extension board in use, see boards/board.h for a list.
CPPFLAGS = \
       -D ARM_MATH_CM0PLUS=true                           \
       -D BOARD=USER_BOARD                                \
       -D EXTINT_CALLBACK_MODE=true                       \
       -D UDD_ENABLE                                      \
       -D USB_DEVICE_LPM_SUPPORT                          \
       -D TCC_ASYNC=true                                  \
       -D __SAMD11D14AM__

# Extra flags to use when linking
LDFLAGS = \
                                                          \
       -Wl,--defsym,STACK_SIZE=0x4CC                      \
       -Wl,--defsym,__stack_size__=0x4CC

# Pre- and post-build commands
PREBUILD_CMD = 
POSTBUILD_CMD = 