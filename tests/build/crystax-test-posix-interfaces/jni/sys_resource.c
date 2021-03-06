/*
 * Copyright (c) 2011-2015 CrystaX.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice, this list of
 *       conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright notice, this list
 *       of conditions and the following disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY CrystaX ''AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL CrystaX OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of CrystaX.
 */

#include <sys/resource.h>

#include "gen/sys_resource.inc"

#include "helper.h"

#define CHECK(type) type JOIN(sys_resource_check_type_, __LINE__)

CHECK(rlim_t);
CHECK(struct rlimit);
CHECK(struct rusage);
CHECK(struct timeval);
CHECK(id_t);

#undef CHECK
#define CHECK(name) void JOIN(sys_resource_check_fields_, __LINE__)(name *s)

CHECK(struct rlimit)
{
    s->rlim_cur = (rlim_t)0;
    s->rlim_max = (rlim_t)0;
}

CHECK(struct rusage)
{
    struct timeval *p1, *p2;
    p1 = &s->ru_utime;
    p2 = &s->ru_stime;
    (void)p1;
    (void)p2;
}

void sys_resource_check_functions()
{
    (void)getpriority(0, (id_t)0);
    (void)getrlimit(0, (struct rlimit *)0);
    (void)getrusage(0, (struct rusage *)0);
    (void)setpriority(0, (id_t)0, 0);
    (void)setrlimit(0, (const struct rlimit *)0);
}
