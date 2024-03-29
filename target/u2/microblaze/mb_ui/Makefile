# System tool locations

HERE = $(shell pwd)
TOOLS = ../../../tools
BIN2HEX = $(TOOLS)/bin2hex
HEX2BIN = $(TOOLS)/hex2bin
MAKEAPPL = $(TOOLS)/makeappl
MAKEMEM   = $(TOOLS)/make_mem
TASS = $(TOOLS)/64tass/64tass
PARSE_IEC = $(TOOLS)/parse_iec.py
PARSE_NANO = $(TOOLS)/parse_nano.py
BOOT = ../2nd_boot
LWIPLIB = ../mb_lwip/result/liblwip.a

# Configuration
SHELL     = bash
CROSS     = mb

# External inputs
ROMS = ../../../roms

# Outputs
RESULT    = ./result
OUTPUT    = ./output

RESULT_FP = $(shell pwd)/result
OUTPUT_FP = $(shell pwd)/output

PRJ      =  mb_ui
PATH_SW  =  ../../../software

VPATH     = $(PATH_SW)/application \
			$(PATH_SW)/application/ultimate \
			$(PATH_SW)/application/mb_hello \
			$(PATH_SW)/filesystem \
			$(PATH_SW)/filemanager \
			$(PATH_SW)/system \
			$(PATH_SW)/io/flash \
			$(PATH_SW)/drive \
			$(PATH_SW)/components \
			$(PATH_SW)/network \
			$(PATH_SW)/userinterface \
			$(PATH_SW)/io/stream \
			$(PATH_SW)/io/c64 \
			$(PATH_SW)/io/rtc \
			$(PATH_SW)/io/usb \
			$(PATH_SW)/io/tape \
			$(PATH_SW)/io/icap \
			$(PATH_SW)/io/sd_card \
			$(PATH_SW)/io/audio \
			$(PATH_SW)/io/overlay \
			$(PATH_SW)/io/command_interface \
			$(PATH_SW)/io/copper \
			$(PATH_SW)/io/network \
			$(PATH_SW)/network/config \
			$(PATH_SW)/io/iec \
			$(PATH_SW)/6502 \
			$(PATH_SW)/ModPlayer_16k \
			$(PATH_SW)/FreeRTOS/Source \
			$(PATH_SW)/FreeRTOS/Source/include \
			$(PATH_SW)/FreeRTOS/Source/portable/microblaze \
			$(PATH_SW)/FreeRTOS/Source/MemMang \
			$(PATH_SW)/lwip-1.4.1/src/include \
			$(PATH_SW)/lwip-1.4.1/src/include/ipv4 \
			$(PATH_SW)/lwip-1.4.1/src/include/posix/sys \
			$(ROMS)

INCLUDES =  $(wildcard $(addsuffix /*.h, $(VPATH)))


SRCS_C   =	mbstart_rtos.c \
			malloc_lock.c \
			itu.c \
			dump_hex.c \
			small_printf.c \
			profiler.c \
			croutine.c \
            event_groups.c \
            list.c \
            queue.c \
            tasks.c \
            timers.c \
            port.c \
            heap_3.c \
            time.c 

# the order of the files is important, because of the static constructors.
# main loop defines two important globals that define the event based polling mechanism:
# poll_list and the event queue. The sources following the main loop are the ones
# that register themselves in the main loop. The file manager is the second important
# root of the application. Devices can register themselves in the file system tree.
# Therefore, the file manager needs to exist.


SRCS_CC	 =  stream.cc \
			memory.cc \
			init_function.cc \
			flash.cc \
			at45_flash.cc \
			at49_flash.cc \
			w25q_flash.cc \
			s25fl_flash.cc \
			config.cc \
			event.cc \
			main_loop.cc \
			sys_calls.cc \
			c64.cc \
			screen.cc \
			keyboard_c64.cc \
			mystring.cc \
			userinterface.cc \
			ui_elements.cc \
			editor.cc \
			pattern.cc \
			ui_stream.cc \
			tree_browser.cc \
			tree_browser_state.cc \
			config_menu.cc \
			context_menu.cc \
			task_menu.cc \
			usb_stub.cc \
			$(PRJ).cc


SRCS_ASM =  mb_crt0.s portasm.s

SRCS_6502 = sidcrt.tas bootcrt.tas cmd_test_rom.tas ulticopy.tas

SRCS_BIN =  chars.bin 1541.bin 1541c.bin 1541-ii.bin sounds.bin module.bin

SRCS_IEC = iec_code_pr.iec iec_code_dr_pr.iec iec_code_dr.iec

SRCS_NANO = nano_minimal.nan

TOOLCHAIN = C:/Xilinx/13.2/ISE_DS/EDK/gnu/microblaze/nt

PATH_INC =  $(addprefix -I, $(VPATH))
OPTIONS  = -g -ffunction-sections -Os -DOS -D_NO_FILE_ACCESS
COPTIONS = $(OPTIONS) -std=c99
CPPOPT   = $(OPTIONS) -fno-exceptions -fno-rtti -fno-threadsafe-statics
LINK 	 = ./mb_app.lds
LLIB     =  -L ../mb_lwip/result \
            -L $(TOOLCHAIN)/microblaze-xilinx-elf/lib \
            -L $(TOOLCHAIN)/lib/gcc/microblaze-xilinx-elf/4.1.2
#LIBS     = -lstdc++ -lsupc++ -lgcc --start-group -lxil -lc -lm --end-group -lgcc
LIBS     =  -llwip -lc -lgcc 
LFLAGS   = --gc-sections 

VPATH   += $(OUTPUT) $(RESULT)

CC		  = $(CROSS)-gcc
CPP		  = $(CROSS)-g++
LD		  = $(CROSS)-ld
OBJDUMP   = $(CROSS)-objdump
OBJCOPY	  = $(CROSS)-objcopy
SIZE	  = $(CROSS)-size

.SUFFIXES:

OBJS_ASM = $(notdir $(SRCS_ASM:%.s=%.o))
OBJS_C   = $(notdir $(SRCS_C:%.c=%.o))
OBJS_CC  = $(notdir $(SRCS_CC:%.cc=%.o))
OBJS_6502 = $(notdir $(SRCS_6502:%.tas=%.o))
OBJS_IEC = $(notdir $(SRCS_IEC:%.iec=%.o))
OBJS_NANO = $(notdir $(SRCS_NANO:%.nan=%.o))
OBJS_BIN = $(notdir $(SRCS_BIN:%.bin=%.bo))

ALL_OBJS      = $(addprefix $(OUTPUT)/,$(OBJS_6502) $(OBJS_ASM) $(OBJS_C) $(OBJS_CC) $(OBJS_BIN) $(OBJS_IEC) $(OBJS_NANO))
ALL_DEP_OBJS  = $(addprefix $(OUTPUT)/,$(OBJS_C) $(OBJS_CC))


.PHONY: hex clean all dep

all: $(OUTPUT) $(RESULT) $(RESULT)/$(PRJ).bin $(OUTPUT)/$(PRJ).mem
#	$(MAKE) -C ../1st_boot

$(OUTPUT):
	@mkdir $(OUTPUT)

$(RESULT):
	@mkdir $(RESULT)
		
$(RESULT)/$(PRJ).bin: $(OUTPUT)/$(PRJ).out
	@echo "Creating Binary $@"
	$(OBJCOPY) -O binary $< $@

%.bo: %.bin
	@echo "Converting $(<F) binary to $(@F).."
	@cd $(dir $(shell find $(VPATH)  -maxdepth 1 -name $(<F))); $(OBJCOPY) -I binary -O elf32-microblaze --binary-architecture MicroBlaze $(<F) $(@F); mv $(@F) $(OUTPUT_FP); cd $(HERE)

#	@cd $(dir $(shell find $(VPATH)  -maxdepth 1 -name $(<F))); $(OBJCOPY) -I binary -O elf32-microblaze --binary-architecture MicroBlaze $(<F) $(OUTPUT_FP)/$(@F); cd $(HERE)

%.65: %.tas
	@echo "Assembling $<"
	@$(TASS) $< --m6502 --nostart -o $(OUTPUT)/$(@F)

%.b: %.iec
	@echo "Assembling IEC processor code $(<F)"
	@python $(PARSE_IEC) $< $(OUTPUT)/$(@F) >python_out_iec

%.b: %.nan
	@echo "Assembling Nano processor code $(<F)"
	@python $(PARSE_NANO) $< $(OUTPUT)/$(@F) >python_out_nano

%.o: %.b
	@echo "Converting $(<F) binary to .o"
	@cd $(OUTPUT); $(OBJCOPY) -I binary -O elf32-microblaze --binary-architecture MicroBlaze $(<F) $@

%.o: %.65
	@echo "Converting .65 binary to .o"
	@cd $(OUTPUT); $(OBJCOPY) -I binary -O elf32-microblaze --binary-architecture MicroBlaze $(<F) $@
    	
%.o: %.s
	@echo "Compiling $<"
	@$(CC) $(OPTIONS) $(PATH_INC) -B. -c -Wa,-ahlms=$(OUTPUT)/$(@:.o=.lst) -o $(OUTPUT)/$(@F) $<

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(COPTIONS) $(PATH_INC) -B. -c -Wa,-ahlms=$(OUTPUT)/$(@:.o=.lst) -o $(OUTPUT)/$(@F) $<

%.o: %.cc
	@echo "Compiling $<"
	@$(CPP) $(CPPOPT) $(PATH_INC) -B. -c -o $(OUTPUT)/$(@F) $<
	@$(CPP) -MM $(PATH_INC) $< >$(OUTPUT)/$(@F:.o=.d)

%.d: %.cc
	@$(CPP) -MM $(PATH_INC) $< >$(OUTPUT)/$(@F:.o=.d)

%.d: %.c
	@$(CC) -MM $(PATH_INC) $< >$(OUTPUT)/$(@F:.o=.d)

$(OUTPUT)/$(PRJ).out: $(LINK) $(OBJS_C) $(OBJS_CC) $(OBJS_ASM) $(OBJS_6502) $(OBJS_BIN) $(OBJS_IEC) $(OBJS_NANO) $(LWIPLIB)
	@echo "Linking..."
	@$(LD) $(LLIB) $(LFLAGS) -T $(LINK) -Map=$(OUTPUT)/$(PRJ).map -o $(OUTPUT)/$(PRJ).out $(ALL_OBJS) $(LIBS)
	@$(SIZE) $(OUTPUT)/$(PRJ).out

$(OUTPUT)/$(PRJ).mem: $(RESULT)/$(PRJ).bin
	@echo "Make mem..."
	@$(MAKEMEM) -w $< 1000000 65536 >$@

# pull in dependency info for *existing* .o files
-include $(ALL_DEP_OBJS:.o=.d)

clean:
	@-rm -rf $(OUTPUT)
	@-rm -rf $(RESULT)

dep:  $(OBJS_CC:.o=.d) $(OBJS_C:.o=.d)
    
