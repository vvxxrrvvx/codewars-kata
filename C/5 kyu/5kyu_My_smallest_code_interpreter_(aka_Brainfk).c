#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 30000

void brainfuck(const char *code, const char *input, char *output) {
    unsigned char memory[MEM_SIZE] = {0};
    unsigned char *ptr = memory;
    const char *input_ptr = input;
    char *output_ptr = output;

    while (*code) {
        switch (*code) {
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                ++*ptr;
                break;
            case '-':
                --*ptr;
                break;
            case '.':
                *output_ptr++ = *ptr;
                break;
            case ',':
                if (*input_ptr) {
                    *ptr = *input_ptr++;
                }
                break;
            case '[':
                if (!*ptr) {
                    int depth = 1;
                    while (depth) {
                        ++code;
                        if (*code == '[') {
                            ++depth;
                        } else if (*code == ']') {
                            --depth;
                        }
                    }
                }
                break;
            case ']':
                if (*ptr) {
                    int depth = 1;
                    while (depth) {
                        --code;
                        if (*code == ']') {
                            ++depth;
                        } else if (*code == '[') {
                            --depth;
                        }
                    }
                }
                break;
        }
        ++code;
    }

    *output_ptr = '\0';
}