#ifndef PATRICIA_TRIE_H
#define PATRICIA_TRIE_H

#include <memory>
#include <string>
#include <vector>
#include <utility>

using namespace std;

struct PatriciaNode {
    bool isWord;
    vector<pair<string, unique_ptr<PatriciaNode>>> children;
    explicit PatriciaNode(bool word = false);
};

class PatriciaTrie {
public:
    PatriciaTrie();

    void insert(const string &word);
    bool search(const string &word) const;
    bool remove(const string &word);
    void display() const;

private:
    unique_ptr<PatriciaNode> root;

    static int findEdge(const PatriciaNode *node, char ch);
    static int commonPrefix(const string &a, const string &b);
    bool removeRec(PatriciaNode *node, const string &key, bool &deleted);
    void displayRec(const PatriciaNode *node, const string &prefix) const;
};

#endif // PATRICIA_TRIE_H
