/*
 * Tulip Indicators
 * https://tulipindicators.org/
 * Copyright (c) 2010-2020 Tulip Charts LLC
 * Lewis Van Winkle (LV@tulipcharts.org)
 *
 * This file is part of Tulip Indicators.
 *
 * Tulip Indicators is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * Tulip Indicators is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Tulip Indicators.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#pragma once

#include "../indicators.h"

/* IMPORTANT USAGE NOTICE:
 *  1. BUFFERS must go in the very end of the struct
 *  2. BUFFER_INIT must go in the order of declaration
 *  3. the zero[3] array must be initialized to zero, e.g. with help of calloc
 *  4. it is ASSUMED that sizeof(double) = 2*sizeof(int)
 */

/* This set of macros implements ring buffer functionality.
 * It was designed with data locality in mind: as opposed to
 * its predecessor buffer.h, it allows the user to manage
 * multiple buffers along with other data as a single chunk
 * of memory, which comes particularly handy when implementing
 * streaming versions of indicators.
 */

/* Example usage:
 * > struct ti_stream {
 * >     int index;
 * >     int progress;
 * >
 * >     BUFFERS(
 * >         BUFFER(a);
 * >         BUFFER(b);
 * >         BUFFER(c);
 * >     );
 * > };
 * >
 * > int ti_xxx_stream_new(TI_REAL const *options, ti_stream **stream) {
 * >     *stream = calloc(1, sizeof(ti_stream));
 * >
 * >     BUFFER_INIT(*stream, a, 5);
 * >     BUFFER_INIT(*stream, b, 8);
 * >     BUFFER_INIT(*stream, c, 13);
 * >
 * >     int size = BUFFERS_SIZE(*stream);
 * >     *stream = realloc(*stream, sizeof(ti_stream) + sizeof(TI_REAL[size]));
 * > }
 * > 
 * > int ti_xxx_stream_run(ti_stream *stream, ...) {
 * >    ...
 * >    TI_REAL a = BUFFER_AT1(stream, buffername, idx);
 * >    ...
 * > }
 */

#define BUFFERS(buffers) struct { double padding; int zero[4]; buffers } buf_info;
#define BUFFER(name) int offset_##name; int size_##name; int index_##name; int padding_##name;
#define BUFFER_INIT(ptr, name, size) do { \
    ((ptr)->buf_info).offset_##name = *(&((ptr)->buf_info).offset_##name-3) + *(&((ptr)->buf_info).offset_##name-4); \
    ((ptr)->buf_info).size_##name = size; \
    ((ptr)->buf_info).index_##name = -1; \
} while (0)
#define BUFFERS_SIZE(ptr) (*((int*)(&((ptr)->buf_info)+1)-3) + *((int*)(&((ptr)->buf_info)+1)-4))
#define BUFFER_AT(result, ptr, name, delta) do { \
    int idx = ((ptr)->buf_info).index_##name + delta; \
    while (idx >= ((ptr)->buf_info).size_##name) { idx -= ((ptr)->buf_info).size_##name; } \
    while (idx < 0) { idx += ((ptr)->buf_info).size_##name; } \
    result = *((TI_REAL*)(&((ptr)->buf_info) + 1) + ((ptr)->buf_info).offset_##name + idx); \
} while (0)
#define BUFFER_AT1(ptr, name, delta) \
    (*((TI_REAL*)(&((ptr)->buf_info) + 1) + ((ptr)->buf_info).offset_##name + (((ptr)->buf_info).index_##name + delta + ((ptr)->buf_info).size_##name) % ((ptr)->buf_info).size_##name))
#define BUFFER_PUSH(ptr, name, value) do { \
    int idx = ((ptr)->buf_info).index_##name + 1; \
    if (idx == ((ptr)->buf_info).size_##name) { idx = 0; } \
    *((TI_REAL*)(&((ptr)->buf_info) + 1) + ((ptr)->buf_info).offset_##name + idx) = value; \
    ((ptr)->buf_info).index_##name = idx; \
} while (0)


#endif /*__LOCALBUFFER_H__*/
