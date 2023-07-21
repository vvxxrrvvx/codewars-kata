#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_ascii(const char *hex, char ascii[]) {
    int len = strlen(hex);
    int i, j = 0;
    for (i = 0; i < len; i += 2, j++) {
        int val = 0;
        if (hex[i] >= '0' && hex[i] <= '9') {
            val = (hex[i] - '0') * 16;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            val = (hex[i] - 'a' + 10) * 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            val = (hex[i] - 'A' + 10) * 16;
        }
        if (hex[i + 1] >= '0' && hex[i + 1] <= '9') {
            val += hex[i + 1] - '0';
        } else if (hex[i + 1] >= 'a' && hex[i + 1] <= 'f') {
            val += hex[i + 1] - 'a' + 10;
        } else if (hex[i + 1] >= 'A' && hex[i + 1] <= 'F') {
            val += hex[i + 1] - 'A' + 10;
        }
        ascii[j] = val;
    }
    ascii[j] = '\0';
}

void to_hex(size_t length, const char ascii[length], char *hex) {
    int i, j = 0;
    for (i = 0; i < length; i++) {
        sprintf(&hex[j], "%02x", ascii[i]);
        j += 2;
    }
    hex[j] = '\0';
}