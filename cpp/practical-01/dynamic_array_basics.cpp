#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
        cin >> nums[i];

    int max_val = *max_element(nums.begin(), nums.end());
    int min_val = *min_element(nums.begin(), nums.end());
    long long sum = 0;
    for (int x : nums) sum += x;

    cout << "Maximum: " << max_val << "\n";
    cout << "Minimum: " << min_val << "\n";
    cout << "Sum: " << sum << "\n";
    return 0;
}