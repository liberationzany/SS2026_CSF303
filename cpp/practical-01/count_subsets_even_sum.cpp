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
    int count = 0;
    for (int mask = 0; mask < total; ++mask) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i))
                sum += nums[i];
        }
        if (sum % 2 == 0)
            count++;
    }
    cout << count << endl;
    return 0;
}