#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        int ans = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int candidate = ans | (1 << bit);
            int cnt = 0;
            bool ok = false;
            for (int i = 0; i < N; i++) {
                if ((arr[i] & candidate) == candidate) {
                    cnt++;
                    if (cnt >= K) {
                        ok = true;
                        break;
                    }
                } else {
                    cnt = 0;
                }
            }
            if (ok) {
                ans = candidate;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}