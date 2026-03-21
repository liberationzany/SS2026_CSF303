#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
        cin >> nums[i];

    int total = 1 << N;
    for (int mask = 1; mask < total; ++mask) { // exclude empty set
        cout << "{";
        bool first = true;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                if (!first) cout << " ";
                cout << nums[i];
                first = false;
            }
        }
        cout << "}" << endl;
    }
    return 0;
}