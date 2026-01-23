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

#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "cursor.h"

bool pgn_cursor_skip_whitespace(char *str, size_t *cursor)
{
    bool skipped = false;

    while (isspace(str[*cursor])) {
        (*cursor)++;
        skipped = true;
    }

    return skipped;
}

bool pgn_cursor_revisit_whitespace(char *str, size_t *cursor)
{
    bool skipped = false;

    while (isspace(str[*cursor - 1])) {
        (*cursor)--;
        skipped = true;
    }

    return skipped;
}

bool pgn_cursor_skip_comment(char *str, size_t *cursor)
{
    if (str[*cursor] != '{')
        return false;

    (*cursor)++;

    unsigned int left_brace_count = 1, right_brace_count = 0; 
    while (right_brace_count != left_brace_count) {
        /* TODO: how to error idk???
         * maybe return corrupted err file idk wtf
         */
        if (str[*cursor] == '\0')
            abort();

        left_brace_count += str[*cursor] == '{';
        right_brace_count += str[*cursor] == '}';
        (*cursor)++;
    }

    return true;
}

bool pgn_cursor_skip_newline(char *str, size_t *cursor)
{
    if (str[*cursor] == '\r') {
        assert(str[(*cursor)++] == '\r');
        assert(str[(*cursor)++] == '\n');
        return true;
    }

    assert(str[(*cursor)++] == '\n');
    return true;
}
