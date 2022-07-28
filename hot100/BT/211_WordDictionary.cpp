#include <bits/stdc++.h>

using namespace std;

class TrieNode{
public:
    vector<TrieNode*> child;
    bool isWord;
    TrieNode() : child(26, nullptr), isWord(false) {};
    ~TrieNode() {
        for (auto c : child) delete c;
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    ~WordDictionary() {
        delete root;
    }
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for (char c : word) {
            int i = c - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return match(word, root, 0);
    }
    
    bool match(string& word, TrieNode* p, int start) {
        if (!p) return false;
        if (start == word.size()) return p->isWord;
        char c = word[start];
        if (c != '.') {
            return match(word, p->child[c - 'a'], start + 1);
        } else {
            for (const auto& child : p->child) {
                if (match(word, child, start + 1))
                    return true;
            }
        }
        return false;
    }
private:
    TrieNode* root;
};