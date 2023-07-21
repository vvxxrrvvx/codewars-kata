#include <string>

std::string factorial(int n) {
if (n < 0) {
return "";
}

// Handle special case of n = 0
if (n == 0) {
    return "1";
}

// Initialize result to 1
std::string result = "1";

// Multiply all integers from 1 to n
for (int i = 1; i <= n; i++) {
    // Multiply each digit of the result by i and carry over any overflow
    int carry = 0;
    for (int j = result.size() - 1; j >= 0; j--) {
        int product = (result[j] - '0') * i + carry;
        result[j] = '0' + (product % 10);
        carry = product / 10;
    }
    // If there is any overflow, add new digits to the beginning of the result
    while (carry > 0) {
        result = static_cast<char>('0' + (carry % 10)) + result;
        carry /= 10;
    }
}

return result;
}