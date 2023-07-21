#include <stdlib.h>

char *stringy(size_t size) {
  char *str = malloc(size + 1);
  for (size_t i = 0; i < size; i++) {
    if (i % 2 == 0) {
      str[i] = '1';
    } else {
      str[i] = '0';
    }
  }
  str[size] = '\0';
  return str;
}