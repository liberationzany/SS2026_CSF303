#include "PatriciaTrie.h"
#include <iostream>
#include <algorithm>

PatriciaNode::PatriciaNode(bool word) : isWord(word) {}

PatriciaTrie::PatriciaTrie() : root(make_unique<PatriciaNode>()) {}

void PatriciaTrie::insert(const string &word) {
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

bool PatriciaTrie::search(const string &word) const {
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

bool PatriciaTrie::remove(const string &word) {
    bool deleted = false;
    removeRec(root.get(), word, deleted);
    return deleted;
}

void PatriciaTrie::display() const {
    displayRec(root.get(), "");
}

int PatriciaTrie::findEdge(const PatriciaNode *node, char ch) {
    for (int i = 0; i < static_cast<int>(node->children.size()); ++i)
        if (!node->children[i].first.empty() && node->children[i].first[0] == ch)
            return i;
    return -1;
}

int PatriciaTrie::commonPrefix(const string &a, const string &b) {
    int i = 0;
    int n = min(a.size(), b.size());
    while (i < n && a[i] == b[i])
        ++i;
    return i;
}

bool PatriciaTrie::removeRec(PatriciaNode *node, const string &key, bool &deleted) {
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

void PatriciaTrie::displayRec(const PatriciaNode *node, const string &prefix) const {
    if (node->isWord)
        cout << "[WORD] " << prefix << "\n";
    for (const auto &edge : node->children)
        displayRec(edge.second.get(), prefix + edge.first);
}

int main() {
    cout << "=== PATRICIA Trie ===\n";
    PatriciaTrie patricia;
    vector<string> words = {"apple", "app", "apply", "bat", "batch", "banana"};
    for (const auto &word : words)
        patricia.insert(word);

    patricia.display();
    cout << "search('banana') = " << (patricia.search("banana") ? "FOUND" : "NOT FOUND") << "\n";
    cout << "remove('banana') -> " << (patricia.remove("banana") ? "OK" : "FAIL") << "\n";
    cout << "search('banana') = " << (patricia.search("banana") ? "FOUND" : "NOT FOUND") << "\n";
    return 0;
}
