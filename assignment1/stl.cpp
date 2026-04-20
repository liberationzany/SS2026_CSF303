#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // ---------- Part (a): vector ----------
    int N;
    cout << "Enter number of integers: ";
    cin >> N;

    vector<int> vec(N);
    cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }

    // Output in reverse using reverse iterators
    cout << "Vector in reverse: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    // ---------- Part (b): deque ----------
    deque<int> dq;
    int ops;
    cout << "Enter number of operations: ";
    cin >> ops;
    cout << "Operations (1: push_back, 2: push_front, 3: pop_front):\n";
    for (int i = 0; i < ops; ++i) {
        int type, val;
        cin >> type;
        if (type == 1) {
            cin >> val;
            dq.push_back(val);
        } else if (type == 2) {
            cin >> val;
            dq.push_front(val);
        } else if (type == 3) {
            if (!dq.empty()) {
                dq.pop_front();
            } else {
                cout << "Deque is empty, cannot pop.\n";
            }
        }
    }

    cout << "Deque contents: ";
    for (const auto &x : dq) {
        cout << x << " ";
    }
    cout << "\n";

    // ---------- Part (c): array ----------
    constexpr int M = 5;  // fixed size
    array<int, M> arr;
    cout << "Enter " << M << " integers: ";
    for (int i = 0; i < M; ++i) {
        cin >> arr[i];
    }

    int sum = accumulate(arr.begin(), arr.end(), 0);
    cout << "Sum of array elements: " << sum << "\n";

    return 0;
}