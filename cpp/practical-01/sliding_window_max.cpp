#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < N; ++i) {
        // Remove out-of-window indices
        while (!dq.empty() && dq.front() <= i - K)
            dq.pop_front();
        // Maintain decreasing order: remove smaller elements
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= K - 1)
            result.push_back(arr[dq.front()]);
    }

    for (int x : result)
        cout << x << " ";
    cout << endl;
    return 0;
}