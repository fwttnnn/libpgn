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

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "annotation.h"
#include "utils/cursor.h"

pgn_annotation_t __pgn_annotation_nag_from_string(char *str, size_t *consumed)
{
    pgn_annotation_t annotation = PGN_ANNOTATION_UNKNOWN;
    size_t cursor = 0;

    /* works for not revisiting whitespaces
     */
    if (str[cursor] != '$')
        return annotation;

    /* NOTE: NAG annotation tends to have $0 followed by another $<num>.
     * thus why the while loop, take the last.
     */
    while (str[cursor] == '$')
    {
        assert(isdigit(str[++cursor]));

        /* TODO: don't discard the rest.
         */
        char *endptr = NULL;
        long num = strtol(str + cursor, &endptr, 10);

        annotation = num;
        cursor += endptr - (str + cursor);

        pgn_cursor_skip_whitespace(str, &cursor);
    }
    pgn_cursor_revisit_whitespace(str, &cursor);

    *consumed += cursor;
    return annotation;
}

pgn_annotation_t __pgn_annotation_from_string(char *str, size_t *consumed)
{
    /* TODO: maybe refactor using strcmp()?
     */
    pgn_annotation_t annotation = PGN_ANNOTATION_UNKNOWN;

    if (str[0] == '\0')
        return annotation;

    if (str[0] == '!') {
        (*consumed)++;
        annotation = PGN_ANNOTATION_GOOD_MOVE;
    }

    if (str[0] == '?') {
        (*consumed)++;
        annotation = PGN_ANNOTATION_MISTAKE;
    }

    if (str[1] == '\0')
        return annotation;

    if (str[0] == '!' && str[1] == '!') {
        (*consumed)++;
        annotation = PGN_ANNOTATION_BRILLIANT_MOVE;
    }

    if (str[0] == '!' && str[1] == '?') {
        (*consumed)++;
        annotation = PGN_ANNOTATION_INTRESTING_MOVE;
    }

    if (str[0] == '?' && str[1] == '!') {
        (*consumed)++;
        annotation = PGN_ANNOTATION_DUBIOUS_MOVE;
    }

    if (str[0] == '?' && str[1] == '?') {
        (*consumed)++;
        annotation = PGN_ANNOTATION_BLUNDER;
    }

    return annotation;
}

pgn_annotation_t pgn_annotation_from_string(char *str)
{
    size_t consumed = 0;
    return __pgn_annotation_from_string(str, &consumed);
}

size_t pgn_annotation_to_string(pgn_annotation_t annotation, char *dest)
{
    switch (annotation) {
    case PGN_ANNOTATION_UNKNOWN: return 0;
    case PGN_ANNOTATION_NULL: break;
    case PGN_ANNOTATION_GOOD_MOVE:
        strcpy(dest, "!");
        return 1;
    case PGN_ANNOTATION_MISTAKE:
        strcpy(dest, "?");
        return 1;
    case PGN_ANNOTATION_BRILLIANT_MOVE:
        strcpy(dest, "!!");
        return 2;
    case PGN_ANNOTATION_BLUNDER:
        strcpy(dest, "??");
        return 2;
    case PGN_ANNOTATION_INTRESTING_MOVE:
        strcpy(dest, "!?");
        return 2;
    case PGN_ANNOTATION_DUBIOUS_MOVE:
        strcpy(dest, "?!");
        return 2;
    }

    int bytes = sprintf(dest, "$%d", annotation);
    assert(bytes >= 0);

    return bytes;
}
