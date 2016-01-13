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
 * framebuffer.c
 *  Created on: Jan 13, 2016
 *      Author: Peter Vanusanik
 *  Contents: 
 */

#include "framebuffer.h"

uint32_t fw;
uint32_t fh;

uint32_t* framebuffer;
uint8_t*  framebuffer_bitmap;

bool init_framebuffer() {

    fw = framebuffer_width();
    fh = framebuffer_height();

    if (fw <= 0 || fh <= 0)
    	return false;

    uint64_t fbitsize = fw*fh;
    uint64_t fbsize = fbitsize*4;
    uintptr_t fb_kernel_address = (uintptr_t) framebuffer_kernel_address();
    uintptr_t fb_bitmap_address = (uintptr_t) framebuffer_bitmap_address();

    framebuffer = (uint32_t*) mmap_kernel_address(fb_kernel_address, fb_kernel_address+fbsize);
    if (framebuffer == NULL) {
    	// TODO: handle error
    	return false;
    }
    framebuffer_bitmap = (uint8_t*) mmap_kernel_address(fb_bitmap_address, fb_bitmap_address+fbitsize);
    if (framebuffer_bitmap == NULL) {
		// TODO: handle error
    	// TODO: munmap
		return false;
	}

    return true;
}

void flip() {
	framebuffer_update();
}
