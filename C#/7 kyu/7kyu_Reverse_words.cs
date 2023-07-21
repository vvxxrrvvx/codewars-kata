#include <stdlib.h>
#include <string.h>

char* reverseWords(const char* text) {
    // allocate memory for the result string
    size_t len = strlen(text);
    char* result = malloc(len + 1);
    if (result == NULL) {
        return NULL;
    }
    
    // reverse each word in the string
    const char* ptr = text;
    char* res = result;
    while (*ptr != '\0') {
        // copy non-space characters to the result
        if (*ptr != ' ') {
            const char* start = ptr;
            while (*ptr != ' ' && *ptr != '\0') {
                ptr++;
            }
            const char* end = ptr - 1;
            
            // copy the reversed word to the result
            while (end >= start) {
                *res++ = *end--;
            }
        }
        
        // copy spaces to the result
        if (*ptr == ' ') {
            *res++ = ' ';
            ptr++;
        }
    }
    
    // null-terminate the result string
    *res = '\0';
    
    return result;
}