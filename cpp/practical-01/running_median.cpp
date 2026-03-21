#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> maxHeap; // lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // upper half

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        // Insert into appropriate heap
        if (maxHeap.empty() || x <= maxHeap.top())
            maxHeap.push(x);
        else
            minHeap.push(x);

        // Balance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Compute median
        double median;
        if (maxHeap.size() == minHeap.size())
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        else
            median = maxHeap.top();

        cout << fixed << setprecision(1) << median << endl;
    }
    return 0;
}