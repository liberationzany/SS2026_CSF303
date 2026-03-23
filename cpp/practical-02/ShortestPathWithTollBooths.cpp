#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> toll(N);
    for (int i = 0; i < N; i++) {
        cin >> toll[i];
    }
    
    // We need to go from booth 1 to booth N. We have M coins, at most K skips.
    // Booths 1..N-1 must be either paid or skipped.
    if (N == 1) {
        cout << "0\n";
        return 0;
    }
    
    vector<int> booths(toll.begin(), toll.end() - 1); // first N-1 booths
    sort(booths.begin(), booths.end());
    
    long long total_cost = 0;
    int paid = 0;
    for (int t : booths) {
        if (total_cost + t <= M) {
            total_cost += t;
            paid++;
        } else {
            break;
        }
    }
    
    int skips = (N - 1) - paid;
    if (skips <= K) {
        // time = (N-1) minutes for paid booths + 2*skips minutes for skipped booths
        int time = (N - 1) + skips;
        cout << time << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}