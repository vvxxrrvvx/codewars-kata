#include <string.h>
#include <stdlib.h>

char* collatz(int n) {
    char* buf;
    char* ret = NULL;

    if (n == 1) {
        ret = strdup("1");
    } else {
        asprintf(&buf, "%d->%s", n, collatz(n % 2 == 0 ? n / 2 : 3 * n + 1));
        ret = strdup(buf);
        free(buf);
    }

    return ret;
}