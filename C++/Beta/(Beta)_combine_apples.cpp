#include <iostream>
#include <queue>
using namespace std;

int apple(int n, int* a) {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < n; i++) {
        min_heap.push(a[i]);
    }
    int total_forces = 0;
    while (min_heap.size() > 1) {
        int pile1 = min_heap.top();
        min_heap.pop();
        int pile2 = min_heap.top();
        min_heap.pop();
        int combined_pile = pile1 + pile2;
        total_forces += combined_pile;
        min_heap.push(combined_pile);
    }
    return total_forces;
}