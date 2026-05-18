#include "BasicTrie.h"
#include <iostream>
#include <vector>

BasicTrie::BasicTrie() : root(new TrieNode()) {}

BasicTrie::~BasicTrie() {
    clear(root);
}

TrieNode::TrieNode() : isWord(false) {
    children.fill(nullptr);
}

void BasicTrie::insert(const string &word) {
    TrieNode *curr = root;
    for (char ch : word) {
        int idx = ch - 'a';
        if (!curr->children[idx])
            curr->children[idx] = new TrieNode();
        curr = curr->children[idx];
    }
    curr->isWord = true;
}

bool BasicTrie::search(const string &word) const {
    TrieNode *curr = root;
    for (char ch : word) {
        int idx = ch - 'a';
        if (!curr->children[idx])
            return false;
        curr = curr->children[idx];
    }
    return curr->isWord;
}

bool BasicTrie::remove(const string &word) {
    bool deleted = false;
    removeRec(root, word, 0, deleted);
    return deleted;
}

bool BasicTrie::removeRec(TrieNode *node, const string &word, int depth, bool &deleted) {
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

bool BasicTrie::noChildren(const TrieNode *node) {
    for (auto child : node->children)
        if (child)
            return false;
    return true;
}

void BasicTrie::clear(TrieNode *node) {
    if (!node)
        return;
    for (auto child : node->children)
        clear(child);
    delete node;
}

int main() {
    cout << "=== Basic Trie ===\n";
    BasicTrie trie;
    vector<string> words = {"apple", "app", "apply", "bat", "batch", "banana"};
    for (const auto &word : words)
        trie.insert(word);

    cout << "search('app') = " << (trie.search("app") ? "FOUND" : "NOT FOUND") << "\n";
    cout << "search('bath') = " << (trie.search("bath") ? "FOUND" : "NOT FOUND") << "\n";
    cout << "remove('apply') -> " << (trie.remove("apply") ? "OK" : "FAIL") << "\n";
    cout << "search('apply') = " << (trie.search("apply") ? "FOUND" : "NOT FOUND") << "\n";
    return 0;
}
