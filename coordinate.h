/* libpgn - PGN file parser.
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

#ifndef __LIBPGN_COORDINATE_H
#define __LIBPGN_COORDINATE_H

#define PGN_COORDINATE_UNKNOWN 0

typedef struct pgn_coordinate_t {
    char file;
    int rank;
} pgn_coordinate_t;

int pgn_coordinate_file_as_index(char file);

#endif // __LIBPGN_COORDINATE_H
