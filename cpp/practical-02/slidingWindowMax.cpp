#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    deque<int> dq;
    for (int i = 0; i < N; i++) {
        // remove smaller elements from back
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        // remove elements out of window
        if (dq.front() <= i - K) {
            dq.pop_front();
        }
        if (i >= K - 1) {
            cout << arr[dq.front()] << " ";
        }
    }
    return 0;
}