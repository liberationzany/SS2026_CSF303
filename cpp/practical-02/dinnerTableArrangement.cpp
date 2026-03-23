#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> mask(N, 0);
        for (int i = 0; i < N; i++) {
            int M;
            cin >> M;
            for (int j = 0; j < M; j++) {
                int a;
                cin >> a;
                mask[i] |= (1 << (a - 1));
            }
        }
        
        // adjacency: i can be next to j if (mask[i] & mask[j]) == 0
        vector<int> adj(N, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && (mask[i] & mask[j]) == 0) {
                    adj[i] |= (1 << j);
                }
            }
        }
        
        if (N == 1) {
            cout << "YES\n";
            continue;
        }
        
        int full = (1 << N) - 1;
        vector<int> dp(1 << N, 0);
        dp[1 << 0] = 1 << 0; // start from friend 0
        
        for (int s = 0; s < (1 << N); s++) {
            if ((s & 1) == 0) continue; // must contain start
            int last_mask = dp[s];
            if (last_mask == 0) continue;
            for (int i = 0; i < N; i++) {
                if (last_mask & (1 << i)) {
                    int cand = adj[i] & ~s;
                    while (cand) {
                        int j = __builtin_ctz(cand);
                        cand &= cand - 1;
                        dp[s | (1 << j)] |= (1 << j);
                    }
                }
            }
        }
        
        if (dp[full] & adj[0]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}