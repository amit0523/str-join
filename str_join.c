
/*
 * License:
 *
 * This file has been released under "unlicense" license
 * (https://unlicense.org).
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or distribute
 * this software, either in source code form or as a compiled binary, for any
 * purpose, commercial or non-commercial, and by any means.
 *
 * For more information about this license, please visit - https://unlicense.org
 */

/*
 * Author: Amit Choudhary
 * Email: amitchoudhary0523 AT gmail DOT com
 */

#include "str_join.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char *str_join(int skip_null_and_empty_strings, const char *delim,
               int num_args, ...)
{

    va_list valist;
    int i = 0;
    size_t iica = 0; // iica - index into character array
    size_t len = 0;
    size_t delim_len = 0;
    size_t total_len = 0;
    int num_delim_to_concat = -1;
    char *new_char_array = NULL;
    char *temp = NULL;

    if (num_args <= 0) {
        return NULL;
    }

    if (delim) {
        delim_len = strlen(delim);
    }

    va_start(valist, num_args);
    for (i = 0; i < num_args; i++) {

        temp = va_arg(valist, char *);

        if (skip_null_and_empty_strings) {
            if ((!temp) || (!*temp)) {
                continue;
            }
        }

        if ((!temp) || (!*temp)) {
            len = 0;
        } else {
            len = strlen(temp);
        }

        total_len = total_len + len;
        num_delim_to_concat = num_delim_to_concat + 1;
        if (num_delim_to_concat > 0) {
            total_len = total_len + delim_len;
        }

    }
    va_end(valist);

    if (total_len == 0) {
        return NULL;
    }

    total_len = total_len + 1; // 1 extra for terminating null byte

    new_char_array = malloc(total_len);
    if (!new_char_array) {
        return NULL;
    }

    va_start(valist, num_args);
    for (i = 0; i < num_args; i++) {

        temp = va_arg(valist, char *);

        if (skip_null_and_empty_strings) {
            if ((!temp) || (!*temp)) {
                continue;
            }
        }

        if ((!temp) || (!*temp)) {
            len = 0;
        } else {
            len = strlen(temp);
        }

        memmove(&(new_char_array[iica]), temp, len);
        iica = iica + len;

        if (num_delim_to_concat > 0) {
            memmove(&(new_char_array[iica]), delim, delim_len);
            iica = iica + delim_len;
            num_delim_to_concat = num_delim_to_concat - 1;
        }

    }
    va_end(valist);

    new_char_array[iica] = 0;

    return new_char_array;

} // end of function str_join()

