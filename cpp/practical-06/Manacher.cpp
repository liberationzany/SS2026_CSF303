#include "Manacher.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string longestPalindromeManacher(const string &s) {
    int n = static_cast<int>(s.size());
    if (n == 0)
        return string();

    string t;
    t.reserve(n * 2 + 3);
    t.push_back('^');
    for (char ch : s) {
        t.push_back('#');
        t.push_back(ch);
    }
    t += "# $";

    int m = static_cast<int>(t.size());
    vector<int> p(m, 0);
    int center = 0, right = 0;

    for (int i = 1; i < m - 1; ++i) {
        int mirror = 2 * center - i;
        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while (t[i + p[i] + 1] == t[i - p[i] - 1])
            ++p[i];

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < m - 1; ++i) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    cout << "=== Manacher ===\n";
    vector<string> samples = {"babad", "cbbd", "racecar", "abba"};
    for (const auto &text : samples) {
        cout << "palindrome in '" << text << "' is '"
             << longestPalindromeManacher(text) << "'\n";
    }
    return 0;
}
