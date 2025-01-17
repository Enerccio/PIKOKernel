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
 * ct_sys.h
 *  Created on: Jan 13, 2016
 *      Author: Peter Vanusanik
 *  Contents: 
 */

#pragma once

#define SYS_ALLOCATE                1
#define SYS_DEALLOCATE              2
#define SYS_GET_PID                 4
#define SYS_SEND_MESSAGE            5
#define SYS_RECEIVE_MESSAGE         6
#define SYS_GET_CTHREAD_PRIORITY    7
#define SYS_FUTEX_WAIT              8
#define SYS_FUTEX_WAKE              9
#define SYS_ALLOC_CONT              10
#define SYS_GET_FMESSAGE_BLOCK		11

#define GMI_PROCESS_CREATE_STAGE_1 1
