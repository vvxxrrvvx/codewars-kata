#include <stdint.h>

uint64_t base64_to_base10(const char *base64) {
const char *digits = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
uint64_t value = 0;
int length = 0;
const char *p = base64;

// Calculate the length of the input string
while (*p) {
length++;
p++;
}

// Calculate the base-10 value of each character and add them up
p = base64;
while (*p) {
const char *q = digits;
int digit_value = 0;

// Find the base-64 value of the current character
while (*q) {
  if (*p == *q) {
    digit_value = q - digits;
    break;
  }
  q++;
}

// Add the base-10 value of the current character to the total
value += digit_value * ((uint64_t)1 << (6 * (length - 1)));
length--;
p++;
}

return value;
}