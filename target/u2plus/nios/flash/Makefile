
CROSS	     = nios2-elf-
ELFTYPE      = elf32-littlenios2
ARCHITECTURE = nios2

include ../../../common/environment.mk

PRJ      =  flash_fpga
FINAL    =  $(RESULT)/$(PRJ).elf 

SRCS_C   =	itu.c \
			dump_hex.c \
            alt_do_ctors.c
                        
SRCS_CC	 =	memory.cc \
                i2c_drv.cc \
                codec.cc \
			prog_flash.cc \
			small_printf.cc \
            stream.cc \
			stream_uart.cc \
			flash.cc \
			at45_flash.cc \
			w25q_flash.cc \
			s25fl_flash.cc \
			config.cc \
			rtc_i2c.cc \
			c64.cc \
			screen.cc \
			screen_vt100.cc \
			keyboard_c64.cc \
			keyboard_vt100.cc \
			keyboard_usb.cc \
			mystring.cc \
            host_stream.cc \
            bist.cc \
			$(PRJ).cc

VPATH +=	$(PATH_SW)/bist
VPATH +=	$(PATH_SW)/FreeRTOS/Source/portable/nios
VPATH +=	$(PATH_SW)/portable/nios
VPATH +=	$(PATH_SW)/niosbsp
VPATH +=	$(PATH_SW)/niosbsp/HAL/inc
VPATH +=	$(PATH_SW)/niosbsp/drivers/inc
VPATH +=	$(PATH_SW)/application/flasher
VPATH +=    ../../../fpga/u2plus_recovery/output_files
VPATH +=    ../../../fpga/u2plus_run/output_files
VPATH +=    ../recovery/result
VPATH +=    ../ultimate/result

SRCS_ASM =  binaries.s
SRCS_ASMS = 
SRCS_6502 = 
SRCS_RBF =  
#ultimate_recovery.rbf ultimate_run.rbf
SRCS_BIN =  chars.bin
SRCS_APP =
#free_rtos_demo.app ultimate.app
SRCS_IEC = 
SRCS_NANO =

PATH_INC =  $(addprefix -I, $(VPATH))
OPTIONS  = -g -ffunction-sections -O0 -DNIOS -DNO_FILE_ACCESS=1 -Wno-write-strings -mno-hw-div -mno-hw-mul -mno-hw-mulx -DRECOVERYAPP=1
COPTIONS = $(OPTIONS) -std=gnu99
CPPOPT   = $(OPTIONS) -fno-exceptions -fno-rtti -fno-threadsafe-statics -fpermissive
BSP      = $(PATH_SW)/nios_appl_bsp
LINK 	 = $(BSP)/linker.x
LIBS2    = $(BSP)/libhal_bsp.a
LFLAGS   = --gc-sections -msys-crt0=$(BSP)/obj/HAL/src/crt0.o

include ../../../common/rules.mk
#$(OUTPUT)/binaries.o: ultimate_recovery.swp ultimate_run.swp

binaries.o: ultimate_recovery.swp ultimate_run.swp ../ultimate/result/ultimate.bin ../recovery/result/recovery.app
