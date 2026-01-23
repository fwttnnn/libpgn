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

#ifndef __LIBPGN_SCORE_H
#define __LIBPGN_SCORE_H

#include <stddef.h>

typedef enum pgn_score_t {
    PGN_SCORE_UNKNOWN = 0,
    PGN_SCORE_ONGOING, // From wikipedia: Recorded as White score, dash, then Black score, or * (other, e.g., the game is ongoing).
    PGN_SCORE_DRAW,
    PGN_SCORE_WHITE_WON,
    PGN_SCORE_BLACK_WON,
    PGN_SCORE_FORFEIT,
    PGN_SCORE_WHITE_FORFEIT,
    PGN_SCORE_BLACK_FORFEIT,
} pgn_score_t;

pgn_score_t __pgn_score_from_string(char *str, size_t *consumed);
pgn_score_t pgn_score_from_string(char *str);
char *pgn_score_to_string(pgn_score_t score);

#endif // __LIBPGN_SCORE_H
