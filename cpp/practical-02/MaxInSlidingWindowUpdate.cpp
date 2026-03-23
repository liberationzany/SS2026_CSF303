#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegTree {
    int n;
    vector<int> tree;
public:
    SegTree(const vector<int>& data) {
        n = data.size();
        int size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
        for (int i = 0; i < n; i++) {
            tree[size + i] = data[i];
        }
        for (int i = size - 1; i > 0; i--) {
            tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    
    void update(int pos, int val) {
        int i = n;
        while (i < n) i <<= 1; // this is wrong, better use stored size
        // We'll store size in class
    }
};

// Simplified: just use a segment tree with size as power of two
class SegTree2 {
    int size;
    vector<int> tree;
public:
    SegTree2(const vector<int>& data) {
        size = 1;
        while (size < (int)data.size()) size <<= 1;
        tree.assign(2 * size, 0);
        for (int i = 0; i < (int)data.size(); i++) {
            tree[size + i] = data[i];
        }
        for (int i = size - 1; i > 0; i--) {
            tree[i] = max(tree[2*i], tree[2*i+1]);
        }
    }
    
    void update(int pos, int val) {
        int i = size + pos;
        tree[i] = val;
        for (i /= 2; i; i /= 2) {
            tree[i] = max(tree[2*i], tree[2*i+1]);
        }
    }
    
    int query(int l, int r) { // inclusive
        l += size;
        r += size;
        int res = -1e9;
        while (l <= r) {
            if (l & 1) {
                res = max(res, tree[l]);
                l++;
            }
            if (!(r & 1)) {
                res = max(res, tree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    SegTree2 seg(arr);
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            pos--; // to 0-index
            seg.update(pos, val);
        } else {
            int i;
            cin >> i;
            i--; // ending index (0-index)
            int left = max(0, i - K + 1);
            cout << seg.query(left, i) << "\n";
        }
    }
    return 0;
}