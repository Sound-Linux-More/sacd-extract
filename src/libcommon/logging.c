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

#include <stdlib.h>
#include "logging.h"

log_module_info_t * lm_main = 0;  

void init_logging(int yes)
{
    if(yes)
    {
// #ifdef __lv2ppu__ 
//     setenv("LOG_MODULES", "all:5", 0); //,bufsize:16384
// #elif !defined(_WIN32)
//     setenv("LOG_MODULES", "all:5", 0); //,bufsize:16384
//     //setenv("LOG_FILE","logfile-sacd_extract.txt",0);
// #endif
#if defined(WIN32) || defined(_WIN32)
        putenv("LOG_MODULES=all:5");
        putenv("LOG_FILE=logfile-sacd_extract.txt");
#else
        setenv("LOG_MODULES", "all:5", 0); //,bufsize:16384
        setenv("LOG_FILE", "logfile-sacd_extract.txt", 0);
#endif
    }

    lm_main = create_log_module("main");
    log_init();
}

void destroy_logging()
{
    log_destroy();
}
