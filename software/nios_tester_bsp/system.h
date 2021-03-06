/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'nios_tester'
 * SOPC Builder design path: ../../fpga/nios_tester/nios_tester.sopcinfo
 *
 * Generated: Sun Nov 10 10:13:31 CET 2019
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x10000820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 62500000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x20
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00000000
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 62500000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x1e
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x20000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x10000820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 62500000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x20
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00000000
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x1e
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x20000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_UART
#define __ALTERA_MSGDMA
#define __ALTERA_NIOS2_GEN2
#define __AVALON2MEM
#define __IO_BRIDGE
#define __JTAG


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/uart_0"
#define ALT_STDERR_BASE 0x90001000
#define ALT_STDERR_DEV uart_0
#define ALT_STDERR_IS_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_uart"
#define ALT_STDIN "/dev/uart_0"
#define ALT_STDIN_BASE 0x90001000
#define ALT_STDIN_DEV uart_0
#define ALT_STDIN_IS_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_uart"
#define ALT_STDOUT "/dev/uart_0"
#define ALT_STDOUT_BASE 0x90001000
#define ALT_STDOUT_DEV uart_0
#define ALT_STDOUT_IS_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_uart"
#define ALT_SYSTEM_NAME "nios_tester"


/*
 * audio_in_dma_csr configuration
 *
 */

#define ALT_MODULE_CLASS_audio_in_dma_csr altera_msgdma
#define AUDIO_IN_DMA_CSR_BASE 0x90004000
#define AUDIO_IN_DMA_CSR_BURST_ENABLE 0
#define AUDIO_IN_DMA_CSR_BURST_WRAPPING_SUPPORT 0
#define AUDIO_IN_DMA_CSR_CHANNEL_ENABLE 0
#define AUDIO_IN_DMA_CSR_CHANNEL_ENABLE_DERIVED 0
#define AUDIO_IN_DMA_CSR_CHANNEL_WIDTH 8
#define AUDIO_IN_DMA_CSR_DATA_FIFO_DEPTH 256
#define AUDIO_IN_DMA_CSR_DATA_WIDTH 32
#define AUDIO_IN_DMA_CSR_DESCRIPTOR_FIFO_DEPTH 8
#define AUDIO_IN_DMA_CSR_DMA_MODE 2
#define AUDIO_IN_DMA_CSR_ENHANCED_FEATURES 0
#define AUDIO_IN_DMA_CSR_ERROR_ENABLE 0
#define AUDIO_IN_DMA_CSR_ERROR_ENABLE_DERIVED 0
#define AUDIO_IN_DMA_CSR_ERROR_WIDTH 8
#define AUDIO_IN_DMA_CSR_IRQ 4
#define AUDIO_IN_DMA_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define AUDIO_IN_DMA_CSR_MAX_BURST_COUNT 2
#define AUDIO_IN_DMA_CSR_MAX_BYTE 1048576
#define AUDIO_IN_DMA_CSR_MAX_STRIDE 1
#define AUDIO_IN_DMA_CSR_NAME "/dev/audio_in_dma_csr"
#define AUDIO_IN_DMA_CSR_PACKET_ENABLE 0
#define AUDIO_IN_DMA_CSR_PACKET_ENABLE_DERIVED 0
#define AUDIO_IN_DMA_CSR_PREFETCHER_ENABLE 0
#define AUDIO_IN_DMA_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define AUDIO_IN_DMA_CSR_RESPONSE_PORT 2
#define AUDIO_IN_DMA_CSR_SPAN 32
#define AUDIO_IN_DMA_CSR_STRIDE_ENABLE 0
#define AUDIO_IN_DMA_CSR_STRIDE_ENABLE_DERIVED 0
#define AUDIO_IN_DMA_CSR_TRANSFER_TYPE "Full Word Accesses Only"
#define AUDIO_IN_DMA_CSR_TYPE "altera_msgdma"


/*
 * audio_in_dma_descriptor_slave configuration
 *
 */

#define ALT_MODULE_CLASS_audio_in_dma_descriptor_slave altera_msgdma
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_BASE 0x90005000
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_BURST_ENABLE 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_BURST_WRAPPING_SUPPORT 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE_DERIVED 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_CHANNEL_WIDTH 8
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_DATA_FIFO_DEPTH 256
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_DATA_WIDTH 32
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_DESCRIPTOR_FIFO_DEPTH 8
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_DMA_MODE 2
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_ENHANCED_FEATURES 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE_DERIVED 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_ERROR_WIDTH 8
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_IRQ -1
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_MAX_BURST_COUNT 2
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_MAX_BYTE 1048576
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_MAX_STRIDE 1
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_NAME "/dev/audio_in_dma_descriptor_slave"
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE_DERIVED 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_PREFETCHER_ENABLE 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_PROGRAMMABLE_BURST_ENABLE 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_RESPONSE_PORT 2
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_SPAN 16
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE_DERIVED 0
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_TRANSFER_TYPE "Full Word Accesses Only"
#define AUDIO_IN_DMA_DESCRIPTOR_SLAVE_TYPE "altera_msgdma"


/*
 * audio_out_dma_csr configuration
 *
 */

#define ALT_MODULE_CLASS_audio_out_dma_csr altera_msgdma
#define AUDIO_OUT_DMA_CSR_BASE 0x90002000
#define AUDIO_OUT_DMA_CSR_BURST_ENABLE 0
#define AUDIO_OUT_DMA_CSR_BURST_WRAPPING_SUPPORT 0
#define AUDIO_OUT_DMA_CSR_CHANNEL_ENABLE 0
#define AUDIO_OUT_DMA_CSR_CHANNEL_ENABLE_DERIVED 0
#define AUDIO_OUT_DMA_CSR_CHANNEL_WIDTH 8
#define AUDIO_OUT_DMA_CSR_DATA_FIFO_DEPTH 256
#define AUDIO_OUT_DMA_CSR_DATA_WIDTH 32
#define AUDIO_OUT_DMA_CSR_DESCRIPTOR_FIFO_DEPTH 8
#define AUDIO_OUT_DMA_CSR_DMA_MODE 1
#define AUDIO_OUT_DMA_CSR_ENHANCED_FEATURES 0
#define AUDIO_OUT_DMA_CSR_ERROR_ENABLE 0
#define AUDIO_OUT_DMA_CSR_ERROR_ENABLE_DERIVED 0
#define AUDIO_OUT_DMA_CSR_ERROR_WIDTH 8
#define AUDIO_OUT_DMA_CSR_IRQ 6
#define AUDIO_OUT_DMA_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define AUDIO_OUT_DMA_CSR_MAX_BURST_COUNT 2
#define AUDIO_OUT_DMA_CSR_MAX_BYTE 1048576
#define AUDIO_OUT_DMA_CSR_MAX_STRIDE 1
#define AUDIO_OUT_DMA_CSR_NAME "/dev/audio_out_dma_csr"
#define AUDIO_OUT_DMA_CSR_PACKET_ENABLE 0
#define AUDIO_OUT_DMA_CSR_PACKET_ENABLE_DERIVED 0
#define AUDIO_OUT_DMA_CSR_PREFETCHER_ENABLE 0
#define AUDIO_OUT_DMA_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define AUDIO_OUT_DMA_CSR_RESPONSE_PORT 2
#define AUDIO_OUT_DMA_CSR_SPAN 32
#define AUDIO_OUT_DMA_CSR_STRIDE_ENABLE 0
#define AUDIO_OUT_DMA_CSR_STRIDE_ENABLE_DERIVED 0
#define AUDIO_OUT_DMA_CSR_TRANSFER_TYPE "Full Word Accesses Only"
#define AUDIO_OUT_DMA_CSR_TYPE "altera_msgdma"


/*
 * audio_out_dma_descriptor_slave configuration
 *
 */

#define ALT_MODULE_CLASS_audio_out_dma_descriptor_slave altera_msgdma
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_BASE 0x90003000
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_BURST_ENABLE 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_BURST_WRAPPING_SUPPORT 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE_DERIVED 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_CHANNEL_WIDTH 8
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_DATA_FIFO_DEPTH 256
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_DATA_WIDTH 32
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_DESCRIPTOR_FIFO_DEPTH 8
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_DMA_MODE 1
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_ENHANCED_FEATURES 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE_DERIVED 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_ERROR_WIDTH 8
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_IRQ -1
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_MAX_BURST_COUNT 2
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_MAX_BYTE 1048576
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_MAX_STRIDE 1
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_NAME "/dev/audio_out_dma_descriptor_slave"
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE_DERIVED 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_PREFETCHER_ENABLE 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_PROGRAMMABLE_BURST_ENABLE 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_RESPONSE_PORT 2
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_SPAN 16
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE_DERIVED 0
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_TRANSFER_TYPE "Full Word Accesses Only"
#define AUDIO_OUT_DMA_DESCRIPTOR_SLAVE_TYPE "altera_msgdma"


/*
 * avalon2mem_0 configuration
 *
 */

#define ALT_MODULE_CLASS_avalon2mem_0 avalon2mem
#define AVALON2MEM_0_BASE 0x0
#define AVALON2MEM_0_IRQ -1
#define AVALON2MEM_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define AVALON2MEM_0_NAME "/dev/avalon2mem_0"
#define AVALON2MEM_0_SPAN 67108864
#define AVALON2MEM_0_TYPE "avalon2mem"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * io_bridge_0 configuration
 *
 */

#define ALT_MODULE_CLASS_io_bridge_0 io_bridge
#define IO_BRIDGE_0_BASE 0x4000000
#define IO_BRIDGE_0_IRQ 0
#define IO_BRIDGE_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define IO_BRIDGE_0_NAME "/dev/io_bridge_0"
#define IO_BRIDGE_0_SPAN 1048576
#define IO_BRIDGE_0_TYPE "io_bridge"


/*
 * io_bridge_1 configuration
 *
 */

#define ALT_MODULE_CLASS_io_bridge_1 io_bridge
#define IO_BRIDGE_1_BASE 0xa0000000
#define IO_BRIDGE_1_IRQ 1
#define IO_BRIDGE_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define IO_BRIDGE_1_NAME "/dev/io_bridge_1"
#define IO_BRIDGE_1_SPAN 1048576
#define IO_BRIDGE_1_TYPE "io_bridge"


/*
 * jtag_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_0 jtag
#define JTAG_0_BASE 0x9000a000
#define JTAG_0_IRQ -1
#define JTAG_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define JTAG_0_NAME "/dev/jtag_0"
#define JTAG_0_SPAN 256
#define JTAG_0_TYPE "jtag"


/*
 * jtag_1 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_1 jtag
#define JTAG_1_BASE 0x9000b000
#define JTAG_1_IRQ -1
#define JTAG_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define JTAG_1_NAME "/dev/jtag_1"
#define JTAG_1_SPAN 256
#define JTAG_1_TYPE "jtag"


/*
 * jtagdebug_csr configuration
 *
 */

#define ALT_MODULE_CLASS_jtagdebug_csr altera_msgdma
#define JTAGDEBUG_CSR_BASE 0x9000e000
#define JTAGDEBUG_CSR_BURST_ENABLE 0
#define JTAGDEBUG_CSR_BURST_WRAPPING_SUPPORT 0
#define JTAGDEBUG_CSR_CHANNEL_ENABLE 0
#define JTAGDEBUG_CSR_CHANNEL_ENABLE_DERIVED 0
#define JTAGDEBUG_CSR_CHANNEL_WIDTH 8
#define JTAGDEBUG_CSR_DATA_FIFO_DEPTH 256
#define JTAGDEBUG_CSR_DATA_WIDTH 8
#define JTAGDEBUG_CSR_DESCRIPTOR_FIFO_DEPTH 8
#define JTAGDEBUG_CSR_DMA_MODE 2
#define JTAGDEBUG_CSR_ENHANCED_FEATURES 0
#define JTAGDEBUG_CSR_ERROR_ENABLE 0
#define JTAGDEBUG_CSR_ERROR_ENABLE_DERIVED 0
#define JTAGDEBUG_CSR_ERROR_WIDTH 8
#define JTAGDEBUG_CSR_IRQ 5
#define JTAGDEBUG_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAGDEBUG_CSR_MAX_BURST_COUNT 2
#define JTAGDEBUG_CSR_MAX_BYTE 8388608
#define JTAGDEBUG_CSR_MAX_STRIDE 1
#define JTAGDEBUG_CSR_NAME "/dev/jtagdebug_csr"
#define JTAGDEBUG_CSR_PACKET_ENABLE 0
#define JTAGDEBUG_CSR_PACKET_ENABLE_DERIVED 0
#define JTAGDEBUG_CSR_PREFETCHER_ENABLE 0
#define JTAGDEBUG_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define JTAGDEBUG_CSR_RESPONSE_PORT 2
#define JTAGDEBUG_CSR_SPAN 32
#define JTAGDEBUG_CSR_STRIDE_ENABLE 0
#define JTAGDEBUG_CSR_STRIDE_ENABLE_DERIVED 0
#define JTAGDEBUG_CSR_TRANSFER_TYPE "Aligned Accesses"
#define JTAGDEBUG_CSR_TYPE "altera_msgdma"


/*
 * jtagdebug_descriptor_slave configuration
 *
 */

#define ALT_MODULE_CLASS_jtagdebug_descriptor_slave altera_msgdma
#define JTAGDEBUG_DESCRIPTOR_SLAVE_BASE 0x9000f000
#define JTAGDEBUG_DESCRIPTOR_SLAVE_BURST_ENABLE 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_BURST_WRAPPING_SUPPORT 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_CHANNEL_ENABLE 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_CHANNEL_ENABLE_DERIVED 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_CHANNEL_WIDTH 8
#define JTAGDEBUG_DESCRIPTOR_SLAVE_DATA_FIFO_DEPTH 256
#define JTAGDEBUG_DESCRIPTOR_SLAVE_DATA_WIDTH 8
#define JTAGDEBUG_DESCRIPTOR_SLAVE_DESCRIPTOR_FIFO_DEPTH 8
#define JTAGDEBUG_DESCRIPTOR_SLAVE_DMA_MODE 2
#define JTAGDEBUG_DESCRIPTOR_SLAVE_ENHANCED_FEATURES 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_ERROR_ENABLE 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_ERROR_ENABLE_DERIVED 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_ERROR_WIDTH 8
#define JTAGDEBUG_DESCRIPTOR_SLAVE_IRQ -1
#define JTAGDEBUG_DESCRIPTOR_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define JTAGDEBUG_DESCRIPTOR_SLAVE_MAX_BURST_COUNT 2
#define JTAGDEBUG_DESCRIPTOR_SLAVE_MAX_BYTE 8388608
#define JTAGDEBUG_DESCRIPTOR_SLAVE_MAX_STRIDE 1
#define JTAGDEBUG_DESCRIPTOR_SLAVE_NAME "/dev/jtagdebug_descriptor_slave"
#define JTAGDEBUG_DESCRIPTOR_SLAVE_PACKET_ENABLE 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_PACKET_ENABLE_DERIVED 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_PREFETCHER_ENABLE 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_PROGRAMMABLE_BURST_ENABLE 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_RESPONSE_PORT 2
#define JTAGDEBUG_DESCRIPTOR_SLAVE_SPAN 16
#define JTAGDEBUG_DESCRIPTOR_SLAVE_STRIDE_ENABLE 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_STRIDE_ENABLE_DERIVED 0
#define JTAGDEBUG_DESCRIPTOR_SLAVE_TRANSFER_TYPE "Aligned Accesses"
#define JTAGDEBUG_DESCRIPTOR_SLAVE_TYPE "altera_msgdma"


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x20000000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "onchip_mem"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 1
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 2048
#define ONCHIP_MEMORY2_0_SPAN 2048
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * pio_0 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_0 altera_avalon_pio
#define PIO_0_BASE 0x90000000
#define PIO_0_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_0_CAPTURE 0
#define PIO_0_DATA_WIDTH 1
#define PIO_0_DO_TEST_BENCH_WIRING 0
#define PIO_0_DRIVEN_SIM_VALUE 0
#define PIO_0_EDGE_TYPE "NONE"
#define PIO_0_FREQ 62500000
#define PIO_0_HAS_IN 1
#define PIO_0_HAS_OUT 0
#define PIO_0_HAS_TRI 0
#define PIO_0_IRQ 2
#define PIO_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PIO_0_IRQ_TYPE "LEVEL"
#define PIO_0_NAME "/dev/pio_0"
#define PIO_0_RESET_VALUE 0
#define PIO_0_SPAN 16
#define PIO_0_TYPE "altera_avalon_pio"


/*
 * pio_1 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_1 altera_avalon_pio
#define PIO_1_BASE 0x90006000
#define PIO_1_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_1_BIT_MODIFYING_OUTPUT_REGISTER 1
#define PIO_1_CAPTURE 0
#define PIO_1_DATA_WIDTH 32
#define PIO_1_DO_TEST_BENCH_WIRING 0
#define PIO_1_DRIVEN_SIM_VALUE 0
#define PIO_1_EDGE_TYPE "NONE"
#define PIO_1_FREQ 62500000
#define PIO_1_HAS_IN 1
#define PIO_1_HAS_OUT 1
#define PIO_1_HAS_TRI 0
#define PIO_1_IRQ -1
#define PIO_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_1_IRQ_TYPE "NONE"
#define PIO_1_NAME "/dev/pio_1"
#define PIO_1_RESET_VALUE 0
#define PIO_1_SPAN 32
#define PIO_1_TYPE "altera_avalon_pio"


/*
 * spi_0 configuration
 *
 */

#define ALT_MODULE_CLASS_spi_0 altera_avalon_spi
#define SPI_0_BASE 0x9000c000
#define SPI_0_CLOCKMULT 1
#define SPI_0_CLOCKPHASE 0
#define SPI_0_CLOCKPOLARITY 0
#define SPI_0_CLOCKUNITS "Hz"
#define SPI_0_DATABITS 8
#define SPI_0_DATAWIDTH 16
#define SPI_0_DELAYMULT "1.0E-9"
#define SPI_0_DELAYUNITS "ns"
#define SPI_0_EXTRADELAY 0
#define SPI_0_INSERT_SYNC 0
#define SPI_0_IRQ 8
#define SPI_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI_0_ISMASTER 1
#define SPI_0_LSBFIRST 0
#define SPI_0_NAME "/dev/spi_0"
#define SPI_0_NUMSLAVES 1
#define SPI_0_PREFIX "spi_"
#define SPI_0_SPAN 32
#define SPI_0_SYNC_REG_DEPTH 2
#define SPI_0_TARGETCLOCK 2000000u
#define SPI_0_TARGETSSDELAY "0.0"
#define SPI_0_TYPE "altera_avalon_spi"


/*
 * uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_uart_0 altera_avalon_uart
#define UART_0_BASE 0x90001000
#define UART_0_BAUD 115200
#define UART_0_DATA_BITS 8
#define UART_0_FIXED_BAUD 1
#define UART_0_FREQ 62500000
#define UART_0_IRQ 3
#define UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_0_NAME "/dev/uart_0"
#define UART_0_PARITY 'N'
#define UART_0_SIM_CHAR_STREAM ""
#define UART_0_SIM_TRUE_BAUD 0
#define UART_0_SPAN 32
#define UART_0_STOP_BITS 1
#define UART_0_SYNC_REG_DEPTH 2
#define UART_0_TYPE "altera_avalon_uart"
#define UART_0_USE_CTS_RTS 1
#define UART_0_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
