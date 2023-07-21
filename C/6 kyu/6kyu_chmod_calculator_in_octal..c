#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *chmod_calculator(char octal[4], const char user[3], const char group[3], const char other[3]) {
    strcpy(octal, "000");

    if (user != NULL) {
        if (user[0] == 'r')
            octal[0] += 4;
        if (user[1] == 'w')
            octal[0] += 2;
        if (user[2] == 'x')
            octal[0] += 1;
    }

    if (group != NULL) {
        if (group[0] == 'r')
            octal[1] += 4;
        if (group[1] == 'w')
            octal[1] += 2;
        if (group[2] == 'x')
            octal[1] += 1;
    }

    if (other != NULL) {
        if (other[0] == 'r')
            octal[2] += 4;
        if (other[1] == 'w')
            octal[2] += 2;
        if (other[2] == 'x')
            octal[2] += 1;
    }

    return octal;
}