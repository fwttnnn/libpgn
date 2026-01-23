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

#ifndef __LIBPGN_PGN_H
#define __LIBPGN_PGN_H

#include "metadata.h"
#include "piece.h"
#include "annotation.h"
#include "coordinate.h"
#include "score.h"
#include "check.h"
#include "moves.h"

#include "utils/export.h"

#define PGN_UNUSED(x) ((void)x)
#define PGN_NOT_IMPLEMENTED()                                                                                      \
    do {                                                                                                           \
        fprintf(stderr, "libpgn: function `%s` is not implemented yet, at %s:%d\n", __func__, __FILE__, __LINE__); \
        exit(EXIT_FAILURE);                                                                                        \
    } while (0)

typedef struct pgn_t {
    pgn_metadata_t *metadata;
    pgn_moves_t *moves;
    pgn_score_t score;
} pgn_t;

PGN_EXPORT pgn_t *pgn_init(void);
PGN_EXPORT void pgn_cleanup(pgn_t *pgn);

PGN_EXPORT pgn_metadata_t *pgn_parse_metadata(char *str);
PGN_EXPORT pgn_move_t pgn_parse_move(char *str);
PGN_EXPORT pgn_moves_t *pgn_parse_moves(char *str);
PGN_EXPORT pgn_score_t pgn_parse_score(char *str);

PGN_EXPORT size_t pgn_parse(pgn_t *pgn, char *str);

#endif // __LIBPGN_PGN_H
