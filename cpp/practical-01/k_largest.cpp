#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    priority_queue<int> pq; // max heap

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        pq.push(x);
    }

    vector<int> result;
    for (int i = 0; i < K; ++i) {
        result.push_back(pq.top());
        pq.pop();
    }

    for (int x : result)
        cout << x << " ";
    cout << endl;
    return 0;
}