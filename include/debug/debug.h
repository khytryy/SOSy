#pragma once

#include <stddef.h>
#include <stdbool.h>

#include <common/common.h>

int     digits_of_int(int num);
void    reverse(char str[], int length);
char*   itoa(int num, char* buffer, int base);

char*   num_to_string(int num);
char*   hex_to_string(int hex);