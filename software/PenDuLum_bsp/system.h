/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'nios_system'
 * SOPC Builder design path: C:/altera/Pendulum/nios_system.sopcinfo
 *
 * Generated: Mon May 22 10:23:01 EST 2017
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

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x100820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x15
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x80020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x15
#define ALT_CPU_NAME "nios2_qsys_0"
#define ALT_CPU_RESET_ADDR 0x80000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x100820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x15
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x80020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x15
#define NIOS2_RESET_ADDR 0x80000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS
#define __ALTERA_UP_AVALON_PARALLEL_PORT
#define __ALTERA_UP_AVALON_SRAM


/*
 * HexDisplay3to0 configuration
 *
 */

#define ALT_MODULE_CLASS_HexDisplay3to0 altera_up_avalon_parallel_port
#define HEXDISPLAY3TO0_BASE 0x101070
#define HEXDISPLAY3TO0_IRQ -1
#define HEXDISPLAY3TO0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEXDISPLAY3TO0_NAME "/dev/HexDisplay3to0"
#define HEXDISPLAY3TO0_SPAN 16
#define HEXDISPLAY3TO0_TYPE "altera_up_avalon_parallel_port"


/*
 * HexDisplay7to4 configuration
 *
 */

#define ALT_MODULE_CLASS_HexDisplay7to4 altera_up_avalon_parallel_port
#define HEXDISPLAY7TO4_BASE 0x101060
#define HEXDISPLAY7TO4_IRQ -1
#define HEXDISPLAY7TO4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEXDISPLAY7TO4_NAME "/dev/HexDisplay7to4"
#define HEXDISPLAY7TO4_SPAN 16
#define HEXDISPLAY7TO4_TYPE "altera_up_avalon_parallel_port"


/*
 * KeyButtons configuration
 *
 */

#define ALT_MODULE_CLASS_KeyButtons altera_up_avalon_parallel_port
#define KEYBUTTONS_BASE 0x1010a0
#define KEYBUTTONS_IRQ -1
#define KEYBUTTONS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define KEYBUTTONS_NAME "/dev/KeyButtons"
#define KEYBUTTONS_SPAN 16
#define KEYBUTTONS_TYPE "altera_up_avalon_parallel_port"


/*
 * LEDGreen configuration
 *
 */

#define ALT_MODULE_CLASS_LEDGreen altera_up_avalon_parallel_port
#define LEDGREEN_BASE 0x101080
#define LEDGREEN_IRQ -1
#define LEDGREEN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDGREEN_NAME "/dev/LEDGreen"
#define LEDGREEN_SPAN 16
#define LEDGREEN_TYPE "altera_up_avalon_parallel_port"


/*
 * LEDRed configuration
 *
 */

#define ALT_MODULE_CLASS_LEDRed altera_up_avalon_parallel_port
#define LEDRED_BASE 0x101090
#define LEDRED_IRQ -1
#define LEDRED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDRED_NAME "/dev/LEDRed"
#define LEDRED_SPAN 16
#define LEDRED_TYPE "altera_up_avalon_parallel_port"


/*
 * MonitorISR configuration
 *
 */

#define ALT_MODULE_CLASS_MonitorISR altera_up_avalon_parallel_port
#define MONITORISR_BASE 0x101040
#define MONITORISR_IRQ -1
#define MONITORISR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MONITORISR_NAME "/dev/MonitorISR"
#define MONITORISR_SPAN 16
#define MONITORISR_TYPE "altera_up_avalon_parallel_port"


/*
 * SliderSW configuration
 *
 */

#define ALT_MODULE_CLASS_SliderSW altera_up_avalon_parallel_port
#define SLIDERSW_BASE 0x101050
#define SLIDERSW_IRQ -1
#define SLIDERSW_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SLIDERSW_NAME "/dev/SliderSW"
#define SLIDERSW_SPAN 16
#define SLIDERSW_TYPE "altera_up_avalon_parallel_port"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone II"
#define ALT_IRQ_BASE NULL
#define ALT_LEGACY_INTERRUPT_API_PRESENT
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x1010c0
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x1010c0
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x1010c0
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_system"


/*
 * beam configuration
 *
 */

#define ALT_MODULE_CLASS_beam altera_up_avalon_parallel_port
#define BEAM_BASE 0x0
#define BEAM_IRQ 3
#define BEAM_IRQ_INTERRUPT_CONTROLLER_ID 0
#define BEAM_NAME "/dev/beam"
#define BEAM_SPAN 16
#define BEAM_TYPE "altera_up_avalon_parallel_port"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x1010c0
#define JTAG_UART_0_IRQ 1
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * motor_voltage configuration
 *
 */

#define ALT_MODULE_CLASS_motor_voltage altera_up_avalon_parallel_port
#define MOTOR_VOLTAGE_BASE 0x101020
#define MOTOR_VOLTAGE_IRQ -1
#define MOTOR_VOLTAGE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MOTOR_VOLTAGE_NAME "/dev/motor_voltage"
#define MOTOR_VOLTAGE_SPAN 16
#define MOTOR_VOLTAGE_TYPE "altera_up_avalon_parallel_port"


/*
 * pio_encoder configuration
 *
 */

#define ALT_MODULE_CLASS_pio_encoder altera_up_avalon_parallel_port
#define PIO_ENCODER_BASE 0x101030
#define PIO_ENCODER_IRQ 2
#define PIO_ENCODER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PIO_ENCODER_NAME "/dev/pio_encoder"
#define PIO_ENCODER_SPAN 16
#define PIO_ENCODER_TYPE "altera_up_avalon_parallel_port"


/*
 * pio_useconds configuration
 *
 */

#define ALT_MODULE_CLASS_pio_useconds altera_up_avalon_parallel_port
#define PIO_USECONDS_BASE 0x1010b0
#define PIO_USECONDS_IRQ -1
#define PIO_USECONDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_USECONDS_NAME "/dev/pio_useconds"
#define PIO_USECONDS_SPAN 16
#define PIO_USECONDS_TYPE "altera_up_avalon_parallel_port"


/*
 * sram_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sram_0 altera_up_avalon_sram
#define SRAM_0_BASE 0x80000
#define SRAM_0_IRQ -1
#define SRAM_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SRAM_0_NAME "/dev/sram_0"
#define SRAM_0_SPAN 524288
#define SRAM_0_TYPE "altera_up_avalon_sram"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x101000
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000
#define TIMER_0_IRQ 0
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999
#define TIMER_0_MULT 0.0010
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000.0
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"


/*
 * ucosii configuration
 *
 */

#define OS_ARG_CHK_EN 1
#define OS_CPU_HOOKS_EN 1
#define OS_DEBUG_EN 1
#define OS_EVENT_NAME_SIZE 32
#define OS_FLAGS_NBITS 16
#define OS_FLAG_ACCEPT_EN 1
#define OS_FLAG_DEL_EN 1
#define OS_FLAG_EN 1
#define OS_FLAG_NAME_SIZE 32
#define OS_FLAG_QUERY_EN 1
#define OS_FLAG_WAIT_CLR_EN 1
#define OS_LOWEST_PRIO 20
#define OS_MAX_EVENTS 60
#define OS_MAX_FLAGS 20
#define OS_MAX_MEM_PART 60
#define OS_MAX_QS 20
#define OS_MAX_TASKS 10
#define OS_MBOX_ACCEPT_EN 1
#define OS_MBOX_DEL_EN 1
#define OS_MBOX_EN 1
#define OS_MBOX_POST_EN 1
#define OS_MBOX_POST_OPT_EN 1
#define OS_MBOX_QUERY_EN 1
#define OS_MEM_EN 1
#define OS_MEM_NAME_SIZE 32
#define OS_MEM_QUERY_EN 1
#define OS_MUTEX_ACCEPT_EN 1
#define OS_MUTEX_DEL_EN 1
#define OS_MUTEX_EN 1
#define OS_MUTEX_QUERY_EN 1
#define OS_Q_ACCEPT_EN 1
#define OS_Q_DEL_EN 1
#define OS_Q_EN 1
#define OS_Q_FLUSH_EN 1
#define OS_Q_POST_EN 1
#define OS_Q_POST_FRONT_EN 1
#define OS_Q_POST_OPT_EN 1
#define OS_Q_QUERY_EN 1
#define OS_SCHED_LOCK_EN 1
#define OS_SEM_ACCEPT_EN 1
#define OS_SEM_DEL_EN 1
#define OS_SEM_EN 1
#define OS_SEM_QUERY_EN 1
#define OS_SEM_SET_EN 1
#define OS_TASK_CHANGE_PRIO_EN 1
#define OS_TASK_CREATE_EN 1
#define OS_TASK_CREATE_EXT_EN 1
#define OS_TASK_DEL_EN 1
#define OS_TASK_IDLE_STK_SIZE 512
#define OS_TASK_NAME_SIZE 32
#define OS_TASK_PROFILE_EN 1
#define OS_TASK_QUERY_EN 1
#define OS_TASK_STAT_EN 1
#define OS_TASK_STAT_STK_CHK_EN 1
#define OS_TASK_STAT_STK_SIZE 512
#define OS_TASK_SUSPEND_EN 1
#define OS_TASK_SW_HOOK_EN 1
#define OS_TASK_TMR_PRIO 0
#define OS_TASK_TMR_STK_SIZE 512
#define OS_THREAD_SAFE_NEWLIB 1
#define OS_TICKS_PER_SEC TIMER_0_TICKS_PER_SEC
#define OS_TICK_STEP_EN 1
#define OS_TIME_DLY_HMSM_EN 1
#define OS_TIME_DLY_RESUME_EN 1
#define OS_TIME_GET_SET_EN 1
#define OS_TIME_TICK_HOOK_EN 1
#define OS_TMR_CFG_MAX 16
#define OS_TMR_CFG_NAME_SIZE 16
#define OS_TMR_CFG_TICKS_PER_SEC 10
#define OS_TMR_CFG_WHEEL_SIZE 2
#define OS_TMR_EN 0

#endif /* __SYSTEM_H_ */
