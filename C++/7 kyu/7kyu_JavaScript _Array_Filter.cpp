#include <vector>

std::vector<int> get_even_numbers(const std::vector<int>& arr) {
  std::vector<int> evenNumbers;
  for (int num : arr) {
    if (num % 2 == 0) {
      evenNumbers.push_back(num);
    }
  }
  return evenNumbers;
}