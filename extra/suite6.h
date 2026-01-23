/* suite6.h - test suite
 *
 * Copyright (c) 2024-2026 fwttnnn <lolywk@tutanota.com>
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef SUITE6_H
#define SUITE6_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ANSI color codes */
#define R "\033[31m"
#define G "\033[32m"
#define B "\033[34;4m"
#define C "\033[0m"

#define suite6_pass(expr)                                                         \
    do {                                                                          \
        printf("%s[PASS] %s%s:%d%s :: %s\n", G, B, __FILE__, __LINE__, C, #expr); \
    } while (0)

#define suite6_fail(expr)                                                         \
    do {                                                                          \
        printf("%s[FAIL] %s%s:%d%s :: %s\n", R, B, __FILE__, __LINE__, C, #expr); \
        abort();                                                                  \
    } while (0)

#define suite6_assert(expr)              \
    if ((bool)(expr)) suite6_pass(expr); \
    else suite6_fail(expr)

#endif // SUITE6_H
