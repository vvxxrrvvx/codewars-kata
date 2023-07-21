#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char *mr_asprintf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    char *result = NULL;
    size_t length = 0;
    const char *p = format;

    while (*p) {
        if (*p == '{' && *(p + 1) == '{') {
            p += 2;
            size_t new_length = length + 1;
            result = realloc(result, new_length + 1);
            if (result == NULL) {
                va_end(args);
                return NULL; // memory allocation error
            }
            *(result + length) = '{';
            length = new_length;
        } else if (*p == '{') {
            const char *q = strchr(p + 1, '}');
            if (q == NULL) {
                va_end(args);
                free(result);
                return NULL; // missing closing brace
            }
            const char *type = p + 1;
            size_t type_len = q - type;
            if (strncmp(type, "i", type_len) == 0) {
                int value = va_arg(args, int);
                char *s = NULL;
                if (asprintf(&s, "%d", value) < 0) {
                    va_end(args);
                    free(result);
                    return NULL; // memory allocation error
                }
                size_t new_length = length + strlen(s);
                result = realloc(result, new_length + 1);
                if (result == NULL) {
                    va_end(args);
                    free(s);
                    return NULL; // memory allocation error
                }
                memcpy(result + length, s, strlen(s));
                length = new_length;
                free(s);
            } else if (strncmp(type, "s", type_len) == 0) {
                char *value = va_arg(args, char *);
                size_t new_length = length + strlen(value);
                result = realloc(result, new_length + 1);
                if (result == NULL) {
                    va_end(args);
                    return NULL; // memory allocation error
                }
                memcpy(result + length, value, strlen(value));
                length = new_length;
            } else {
                va_end(args);
                free(result);
                return NULL; // unsupported type
            }
            p = q + 1;
        } else {
            const char *q = strchr(p + 1, '{');
            if (q == NULL) {
                q = strchr(p + 1, '\0');
            }
            size_t n = q - p;
            size_t new_length = length + n;
            result = realloc(result, new_length + 1);
            if (result == NULL) {
                va_end(args);
                return NULL; // memory allocation error
            }
            memcpy(result + length, p, n);
            length = new_length;
            p = q;
        }
    }

    va_end(args);
    result = realloc(result, length + 1);
    if (result == NULL) {
        return NULL; // memory allocation error
    }
    *(result + length) = '\0';
    return result;
}