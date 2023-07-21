#include <cstdint>
#include <vector>

uint64_t hamber(int n)
{
std::vector<uint64_t> h(n);
h[0] = 1;
int i = 0, j = 0, k = 0;
for (int m = 1; m < n; m++) {
uint64_t next = std::min(2 * h[i], std::min(3 * h[j], 5 * h[k]));
if (next == 2 * h[i]) i++;
if (next == 3 * h[j]) j++;
if (next == 5 * h[k]) k++;
h[m] = next;
}
return h[n - 1];
}