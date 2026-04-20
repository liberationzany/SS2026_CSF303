#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    cin >> K;

    int count = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        long long sum = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        if (sum % K == 0) {
            count++;
        }
    }
    cout << "Number of subsets with sum divisible by " << K << ": " << count << "\n";
    return 0;
}