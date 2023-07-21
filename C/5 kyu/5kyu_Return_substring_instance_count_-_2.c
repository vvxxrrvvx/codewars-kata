#include <stdbool.h>

int search_substr(const char *full_text, const char *search_text, bool allow_overlap) {
    if (search_text[0] == '\0') {
        return 0;  
    }

    int count = 0;
    int full_text_length = strlen(full_text);
    int search_text_length = strlen(search_text);

    for (int i = 0; i <= full_text_length - search_text_length; i++) {
        bool found = true;

        for (int j = 0; j < search_text_length; j++) {
            if (full_text[i + j] != search_text[j]) {
                found = false;
                break;
            }
        }

        if (found) {
            count++;
            if (!allow_overlap) {
                i += search_text_length - 1;
            }
        }
    }

    return count;
}