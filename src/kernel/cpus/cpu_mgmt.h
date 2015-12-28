/*
 * The MIT License (MIT)
 * Copyright (c) 2015 Peter Vanusanik <admin@en-circle.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal in 
 * the Software without restriction, including without limitation the rights to use, copy, 
 * modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, subject to the 
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies 
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS 
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * cpu_mgmt.h
 *  Created on: Dec 23, 2015
 *      Author: Peter Vanusanik
 *  Contents: cpu management
 */

#pragma once

#include "../commons.h"
#include "../utils/random.h"
#include "../memory/paging.h"
#include "../utils/collections/array.h"
#include "../structures/acpi.h"
#include "../tasks/task.h"

#include <stdlib.h>
#include <string.h>

typedef struct cpu {
	void*	 stack;
	void*    handler_stack;
	void*    pf_stack;
	void*    df_stack;
	void*    ipi_stack;

	size_t   insert_id;
	uint64_t processor_id;
	uint8_t  apic_id;

	volatile uint64_t __cpu_lock;
	volatile uint64_t __message_clear_lock;
	volatile uint64_t apic_message;
	volatile uint64_t apic_message2;
	volatile bool apic_message_handled;
	volatile uint8_t apic_message_type;

	volatile uint64_t __cpu_sched_lock;

	volatile bool started;
	array_t* processes;
} cpu_t;

extern array_t* cpus;
extern uint32_t apicaddr;

/**
 * Initializes cpu information. Initializes SMP if available.
 */
void initialize_cpus();

void initialize_mp(unsigned int localcpu);

/**
 * Sends interprocessor interrupt to a processor.
 *
 * Processor is identified by apic_id, vector is data sent,
 * control flags and init_ipi decides flags to be sent with.
 */
void send_ipi_to(uint8_t apic_id, uint8_t vector, uint32_t control_flags, bool init_ipi);

/**
 * Returns pointer to current cpu's cput structure
 */
cpu_t* get_current_cput();

/**
 * Search cpu array by apic predicate
 */
bool search_for_cpu_by_apic(void* e, void* d);

/**
 * Returns local processor_id from MADT, bound local for every cpu
 */
uint8_t get_local_processor_id();

/**
 * Returns local apic_id from MADT, bound local for every cpu
 */
uint8_t get_local_apic_id();

/**
 * Enables IPI interrupts
 */
void enable_ipi_interrupts();

/**
 * Disable IPI interrupts
 */
void disable_ipi_interrupts();
