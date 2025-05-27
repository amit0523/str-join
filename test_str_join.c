
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

static int mystrcmp(const char *result, const char *expected);
static void verify_result(char *result, const char *expected, int line_num,
                          const char *file_name);

int main(void)
{

    char *result = NULL;
    char *expected = NULL;

    printf("\n");
    printf("-----------------------------\n");
    printf("Running automated test cases.\n");
    printf("-----------------------------\n");

    result = str_join(0, "-", 0);
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 0, "abc");
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 0, "");
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 0, NULL);
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 1, "abc");
    expected = "abc";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 1, "");
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 1, NULL);
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 2, "abc", "123");
    expected = "abc-123";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 2, "abc", "");
    expected = "abc-";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 2, NULL, "abc");
    expected = "-abc";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 2, "", NULL);
    expected = "-";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 3, "abc", "123", "fgh");
    expected = "abc-123-fgh";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 3, "", "123", "fgh");
    expected = "-123-fgh";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 3, "abc", NULL, "fgh");
    expected = "abc--fgh";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 3, "abc", "123", "");
    expected = "abc-123-";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 3, NULL, "NULL", "");
    expected = "-NULL-";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 3, "abc", "", NULL);
    expected = "abc--";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-", 3, "", NULL, "abc");
    expected = "--abc";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-?-", 4, "a", "b", "cd", "e");
    expected = "a-?-b-?-cd-?-e";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-?-", 4, "a", NULL, "cd", "e");
    expected = "a-?--?-cd-?-e";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-?-", 4, "a", "", "cd", "");
    expected = "a-?--?-cd-?-";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "-?-", 10, "1", "2", "3", "4", "5", "6", "7", "8", "9",
                      "10");
    expected = "1-?-2-?-3-?-4-?-5-?-6-?-7-?-8-?-9-?-10";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "", 4, "a", "b", "cd", "e");
    expected = "abcde";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, NULL, 4, "a", NULL, "cd", "e");
    expected = "acde";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, NULL, 4, "a", "", "cd", "");
    expected = "acd";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(0, "", 10, "1", "2", "3", "4", "5", "6", "7", "8", "9",
                      "10");
    expected = "12345678910";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 0);
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 0, "abc");
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 0, "");
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 0, NULL);
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 1, "abc");
    expected = "abc";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 1, "");
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 1, NULL);
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 2, "abc", "123");
    expected = "abc-123";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 2, "abc", "");
    expected = "abc";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 2, NULL, "abc");
    expected = "abc";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 2, "", NULL);
    expected = NULL;
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 3, "abc", "123", "fgh");
    expected = "abc-123-fgh";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 3, "", "123", "fgh");
    expected = "123-fgh";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 3, "abc", NULL, "fgh");
    expected = "abc-fgh";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 3, "abc", "123", "");
    expected = "abc-123";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 3, NULL, "NULL", "");
    expected = "NULL";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 3, "abc", "", NULL);
    expected = "abc";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-", 3, "", NULL, "abc");
    expected = "abc";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-?-", 4, "a", "b", "cd", "e");
    expected = "a-?-b-?-cd-?-e";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-?-", 4, "a", NULL, "cd", "e");
    expected = "a-?-cd-?-e";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-?-", 4, "a", "", "cd", "");
    expected = "a-?-cd";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "-?-", 10, "1", "2", "3", "4", "5", "6", "7", "8", "9",
                      "10");
    expected = "1-?-2-?-3-?-4-?-5-?-6-?-7-?-8-?-9-?-10";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "", 4, "a", "b", "cd", "e");
    expected = "abcde";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, NULL, 4, "a", NULL, "cd", "e");
    expected = "acde";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, NULL, 4, "a", "", "cd", "");
    expected = "acd";
    verify_result(result, expected, __LINE__, __FILE__);

    result = str_join(1, "", 10, "1", "2", "3", "4", "5", "6", "7", "8", "9",
                      "10");
    expected = "12345678910";
    verify_result(result, expected, __LINE__, __FILE__);

    printf("\n------------------------------------\n");
    printf("Success: All test cases have passed.\n");
    printf("------------------------------------\n\n");

    return 0;

} // end of function main()

static int mystrcmp(const char *result, const char *expected)
{

    if ((!result) && (!expected)) {
        return 0;
    } else if ((!result) || (!expected)) {
        return 1;
    }

    return strcmp(result, expected);

} // end of function mystrcmp()

static void verify_result(char *result, const char *expected, int line_num,
                          const char *file_name)
{

    int ret_val = -1;

    printf("\n");

    if (result) {
        printf("Result = \"%s\"\n", result);
    } else {
        printf("Result = NULL\n");
    }

    if (expected) {
        printf("Expected = \"%s\"\n", expected);
    } else {
        printf("Expected = NULL\n");
    }

    ret_val = mystrcmp(result, expected);

    free(result);

    if (ret_val != 0) {
        printf("Test case failed. Check the test case just before the line"
               " number %d in the file \"%s\".\n", line_num, file_name);
        printf("\nExiting ..\n\n");
        exit(1);
    } else {
        printf("Test case passed.\n");
    }

    return;

} // end of function verify_result()

