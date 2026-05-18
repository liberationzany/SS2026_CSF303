#ifndef BASIC_TRIE_H
#define BASIC_TRIE_H

#include <array>
#include <string>

using namespace std;

struct TrieNode {
    bool isWord;
    array<TrieNode*, 26> children;
    TrieNode();
};

class BasicTrie {
public:
    BasicTrie();
    ~BasicTrie();

    void insert(const string &word);
    bool search(const string &word) const;
    bool remove(const string &word);

private:
    TrieNode *root;

    bool removeRec(TrieNode *node, const string &word, int depth, bool &deleted);
    static bool noChildren(const TrieNode *node);
    static void clear(TrieNode *node);
};

#endif // BASIC_TRIE_H
