
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

#ifndef _STR_JOIN_H_
#define _STR_JOIN_H_

/*
 * char *str_join(int skip_null_and_empty_strings, const char *delim,
 *                int num_args, ...):
 *
 * Function str_join() concatenates all the strings passed to it. If 'delim' is
 * not NULL and not empty then the 'delim' is concatenated between every two
 * strings.
 *
 * Argument 'num_args' is the total number of strings passed to this function.
 *
 * This function expects that all arguments after 'num_args' should be either
 * pointers to null-terminated strings or a mix of null-terminated strings,
 * NULL, and empty strings. Any other type(s) of argument may make this function
 * behave strangely and this function may even crash also.
 *
 * If 'skip_null_and_empty_strings' is true then this means that NULL/empty
 * strings should be considered valid strings for the purpose of concatenating
 * 'delim' string - this means that if there is a NON-NULL/non-empty string in
 * the variable arguments list which is then followed or preceded by a
 * NULL/empty string then one 'delim' string will be concatenated between
 * NON-NULL/non-empty string and NULL/empty string. This can be useful in case
 * columns of a database are concatenated to form a record which will then be
 * written in a file - so here, a column containing NULL/empty value will be
 * represented as empty by having two consecutive 'delim' strings.
 *
 * If 'skip_null_and_empty_strings' is not true then this means that
 * NULL/empty strings should be skipped and no 'delim' string should be
 * concatenated for them.
 *
 * This function allocates a new character array whose size is equal to the sum
 * of the lengths of all strings passed to it plus 1 (extra 1 for the
 * terminating null character). It then concatenates all the strings passed to
 * it (these strings are separated by 'delim' string but please see above for
 * NULL/empty strings) into the newly allocated character array and then returns
 * the pointer to the newly allocated character array. If memory allocation
 * fails then NULL is returned.
 *
 * It is necessary to check the return value of this functon for NULL before
 * proceeding ahead.
 *
 * The memory for the returned string is allocated using malloc(), so it is the
 * user's responsibility to free this memory.
 */
char *str_join(int skip_null_and_empty_strings, const char *delim,
               int num_args, ...);

#endif

