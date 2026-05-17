#include <debug/debug.h>

int digits_of_int(int num) {
    if (num == 0)
        return 1;

    size_t i = 0;

    while (num != 0) {
        num = num / 10;
        i++;
    }

    return i;
}

void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

char* itoa(int num, char* buffer, int base) {
    size_t i        = 0;
    bool negative   = false;

    if (num == 0) {
        buffer[i++] = '0';
        buffer[i]   = '\0';
        return buffer;
    }

    if (num < 0 && base == 10) {
        negative    = true;
        num         = -num;
    }

    while (num != 0) {
        int rem = num % base;
        buffer[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
        num = num / base;
    }

    if (negative)
        buffer[i++] = '-';

    buffer[i] = '\0';
    reverse(buffer, strlen(buffer));

    return buffer;
}


char* num_to_string(int num) {
    
}

char* hex_to_string(int hex) {
    
}