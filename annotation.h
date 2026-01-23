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

#ifndef __LIBPGN_ANNOTATION_H
#define __LIBPGN_ANNOTATION_H

#include <stdlib.h>

/* See:
 *   http://www.saremba.de/chessgml/standards/pgn/pgn-complete.htm#c10
 *   https://en.wikipedia.org/wiki/Numeric_Annotation_Glyphs#Standard_NAGs
 */
typedef enum pgn_annotation_t {
    PGN_ANNOTATION_UNKNOWN = -1,    //
    PGN_ANNOTATION_NULL = 0,        //
    PGN_ANNOTATION_GOOD_MOVE,       // !
    PGN_ANNOTATION_MISTAKE,         // ?
    PGN_ANNOTATION_BRILLIANT_MOVE,  // !!
    PGN_ANNOTATION_BLUNDER,         // ??
    PGN_ANNOTATION_INTRESTING_MOVE, // !?
    PGN_ANNOTATION_DUBIOUS_MOVE,    // ?!
} pgn_annotation_t;

pgn_annotation_t __pgn_annotation_nag_from_string(char *str, size_t *consumed);
pgn_annotation_t __pgn_annotation_from_string(char *str, size_t *consumed);
pgn_annotation_t pgn_annotation_from_string(char *str);
size_t pgn_annotation_to_string(pgn_annotation_t annotation, char *dest);

#endif // __LIBPGN_ANNOTATION_H
