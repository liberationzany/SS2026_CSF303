#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct TrieNode {
    bool isWord;
    array<TrieNode*, 26> children;
    TrieNode() : isWord(false) {
        children.fill(nullptr);
    }
};

class BasicTrie {
public:
    BasicTrie() : root(new TrieNode()) {}
    ~BasicTrie() { clear(root); }

    void insert(const string &word) {
        TrieNode *curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx])
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isWord = true;
    }

    bool search(const string &word) const {
        TrieNode *curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return curr->isWord;
    }

    bool remove(const string &word) {
        bool deleted = false;
        removeRec(root, word, 0, deleted);
        return deleted;
    }

private:
    TrieNode *root;

    bool removeRec(TrieNode *node, const string &word, int depth, bool &deleted) {
        if (!node)
            return false;

        if (depth == static_cast<int>(word.size())) {
            if (!node->isWord)
                return false;
            node->isWord = false;
            deleted = true;
            return noChildren(node);
        }

        int idx = word[depth] - 'a';
        if (!node->children[idx])
            return false;

        bool shouldDeleteChild = removeRec(node->children[idx], word, depth + 1, deleted);
        if (shouldDeleteChild) {
            delete node->children[idx];
            node->children[idx] = nullptr;
            return !node->isWord && noChildren(node);
        }
        return false;
    }

    static bool noChildren(const TrieNode *node) {
        for (auto child : node->children)
            if (child)
                return false;
        return true;
    }

    static void clear(TrieNode *node) {
        if (!node)
            return;
        for (auto child : node->children)
            clear(child);
        delete node;
    }
};

struct PatriciaNode {
    bool isWord;
    vector<pair<string, unique_ptr<PatriciaNode>>> children;
    explicit PatriciaNode(bool word = false) : isWord(word) {}
};

class PatriciaTrie {
public:
    PatriciaTrie() : root(make_unique<PatriciaNode>()) {}

    void insert(const string &word) {
        PatriciaNode *curr = root.get();
        string remaining = word;

        while (!remaining.empty()) {
            int edgeIndex = findEdge(curr, remaining[0]);
            if (edgeIndex < 0) {
                auto node = make_unique<PatriciaNode>(true);
                curr->children.emplace_back(remaining, move(node));
                return;
            }

            auto &edge = curr->children[edgeIndex];
            string &label = edge.first;
            int common = commonPrefix(label, remaining);

            if (common == static_cast<int>(label.size()) && common == static_cast<int>(remaining.size())) {
                edge.second->isWord = true;
                return;
            }

            if (common == static_cast<int>(label.size())) {
                curr = edge.second.get();
                remaining = remaining.substr(common);
                continue;
            }

            string oldSuffix = label.substr(common);
            auto oldChild = move(edge.second);
            auto splitNode = make_unique<PatriciaNode>();
            splitNode->children.emplace_back(oldSuffix, move(oldChild));

            if (common == static_cast<int>(remaining.size())) {
                splitNode->isWord = true;
            } else {
                string newSuffix = remaining.substr(common);
                auto nextNode = make_unique<PatriciaNode>(true);
                splitNode->children.emplace_back(newSuffix, move(nextNode));
            }

            edge.first = label.substr(0, common);
            edge.second = move(splitNode);
            return;
        }

        curr->isWord = true;
    }

    bool search(const string &word) const {
        const PatriciaNode *curr = root.get();
        string remaining = word;

        while (!remaining.empty()) {
            int edgeIndex = findEdge(curr, remaining[0]);
            if (edgeIndex < 0)
                return false;

            const auto &edge = curr->children[edgeIndex];
            const string &label = edge.first;
            int common = commonPrefix(label, remaining);
            if (common != static_cast<int>(label.size()))
                return false;

            remaining = remaining.substr(common);
            curr = edge.second.get();
        }
        return curr->isWord;
    }

    bool remove(const string &word) {
        bool deleted = false;
        removeRec(root.get(), word, deleted);
        return deleted;
    }

    void display() const {
        displayRec(root.get(), "");
    }

private:
    unique_ptr<PatriciaNode> root;

    static int findEdge(const PatriciaNode *node, char ch) {
        for (int i = 0; i < static_cast<int>(node->children.size()); ++i)
            if (!node->children[i].first.empty() && node->children[i].first[0] == ch)
                return i;
        return -1;
    }

    static int commonPrefix(const string &a, const string &b) {
        int i = 0;
        int n = min(a.size(), b.size());
        while (i < n && a[i] == b[i])
            ++i;
        return i;
    }

    bool removeRec(PatriciaNode *node, const string &key, bool &deleted) {
        if (key.empty()) {
            if (!node->isWord)
                return false;
            node->isWord = false;
            deleted = true;
            return node->children.empty();
        }

        int edgeIndex = findEdge(node, key[0]);
        if (edgeIndex < 0)
            return false;

        auto &edge = node->children[edgeIndex];
        const string &label = edge.first;
        int common = commonPrefix(label, key);
        if (common != static_cast<int>(label.size()))
            return false;

        bool childRemoved = removeRec(edge.second.get(), key.substr(common), deleted);
        if (childRemoved) {
            node->children.erase(node->children.begin() + edgeIndex);
            return node->children.empty() && !node->isWord;
        }

        if (!edge.second->isWord && edge.second->children.size() == 1) {
            auto childEdge = move(edge.second->children[0]);
            edge.first += childEdge.first;
            edge.second = move(childEdge.second);
        }

        return false;
    }

    void displayRec(const PatriciaNode *node, const string &prefix) const {
        if (node->isWord)
            cout << "[WORD] " << prefix << "\n";
        for (const auto &edge : node->children)
            displayRec(edge.second.get(), prefix + edge.first);
    }
};

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
    cout << "=== Single-file Demo ===\n";

    BasicTrie trie;
    vector<string> words = {"apple", "app", "apply", "bat", "batch", "banana"};
    for (const auto &word : words)
        trie.insert(word);

    cout << "search(\"apple\") = " << (trie.search("apple") ? "FOUND" : "NOT FOUND") << "\n";
    cout << "search(\"bath\") = " << (trie.search("bath") ? "FOUND" : "NOT FOUND") << "\n";
    cout << "remove(\"apply\") -> " << (trie.remove("apply") ? "OK" : "FAIL") << "\n";
    cout << "search(\"apply\") = " << (trie.search("apply") ? "FOUND" : "NOT FOUND") << "\n\n";

    PatriciaTrie patricia;
    for (const auto &word : words)
        patricia.insert(word);

    cout << "Patricia initial words:\n";
    patricia.display();
    cout << "\nsearch(\"banana\") = " << (patricia.search("banana") ? "FOUND" : "NOT FOUND") << "\n";
    cout << "remove(\"banana\") -> " << (patricia.remove("banana") ? "OK" : "FAIL") << "\n";
    cout << "search(\"banana\") = " << (patricia.search("banana") ? "FOUND" : "NOT FOUND") << "\n\n";

    vector<string> samples = {"babad", "cbbd", "racecar", "abba"};
    for (const auto &text : samples) {
        cout << "palindrome in \"" << text << "\" is \""
             << longestPalindromeManacher(text) << "\"\n";
    }

    return 0;
}
