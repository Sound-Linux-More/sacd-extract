/**
 * SACD Ripper - https://github.com/sacd-ripper/
 *
 * Copyright (c) 2010-2015 by respective authors.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef __SYS_IO_BUFFER_H__
#define __SYS_IO_BUFFER_H__

#ifndef __lv2ppu__
#error you need the psl1ght/lv2 ppu compatible compiler!
#endif

#include <stdint.h>
#include <ppu-lv2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int sys_io_buffer_t; 
typedef int sys_io_block_t; 

static inline int sys_io_buffer_create(int io_block_count, int block_size, int blocks, int unknown_3, sys_io_buffer_t *io_buffer)
{
    // unknown_3, alignment? (spotted: 512, 1024, any other value == crash)

    lv2syscall5(624, io_block_count, block_size, blocks, unknown_3 & 0x600, (uint64_t) io_buffer);

    return_to_user_prog(int);
}

static inline int sys_io_buffer_destroy(sys_io_buffer_t io_buffer)
{
    lv2syscall1(625, io_buffer);
    return_to_user_prog(int);
}

static inline int sys_io_buffer_allocate(sys_io_buffer_t io_buffer, sys_io_block_t *block)
{
    lv2syscall2(626, io_buffer, (uint64_t) block);
    return_to_user_prog(int);
}

static inline int sys_io_buffer_free(sys_io_buffer_t io_buffer, sys_io_block_t block)
{
    lv2syscall2(627, io_buffer, block);
    return_to_user_prog(int);
}

#ifdef __cplusplus
};
#endif
#endif /* _SYS_IO_BUFFER_H__ */
