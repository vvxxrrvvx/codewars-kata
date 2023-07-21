#include <stddef.h> /* NULL */
#include <string.h> /* strcmp, strncpy */
#include <stdlib.h> /* malloc, realloc */

int wildcard_match(const char *pattern, const char *filename)
{
    while (*pattern && *filename) {
        if (*pattern != '?' && *pattern != *filename)
            return 0;
        pattern++;
        filename++;
    }
    return (*pattern == '\0' && *filename == '\0');
}

char **match(const char *pattern, const char **filenames)
{
    // Count the number of matching filenames
    int count = 0;
    const char **ptr = filenames;
    while (*ptr) {
        if (wildcard_match(pattern, *ptr))
            count++;
        ptr++;
    }

    // Allocate memory for the result array
    char **result = malloc((count + 1) * sizeof(char*));
    if (!result)
        return NULL;

    // Copy matching filenames to the result array
    count = 0;
    ptr = filenames;
    while (*ptr) {
        if (wildcard_match(pattern, *ptr)) {
            result[count] = malloc(strlen(*ptr) + 1);
            if (!result[count])
                return NULL;
            strncpy(result[count], *ptr, strlen(*ptr) + 1);
            count++;
        }
        ptr++;
    }
    result[count] = NULL;

    return result;
}
