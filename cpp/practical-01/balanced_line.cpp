#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    deque<int> dq;

    while (Q--) {
        string op;
        cin >> op;
        if (op == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        } else if (op == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        } else if (op == "pop_front") {
            if (!dq.empty()) dq.pop_front();
        } else if (op == "pop_back") {
            if (!dq.empty()) dq.pop_back();
        }

        // Print current line contents
        for (auto it = dq.begin(); it != dq.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    return 0;
}