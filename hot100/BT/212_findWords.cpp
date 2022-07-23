#include <bits/stdc++.h>

using namespace std;

// 三个方法降低时间复杂度
// 1. 对字典树用回溯法，而不是每一个字符都从头开始遍历字典树
// 2. 对已经找到的单词，字典树叶子节点的string置空
// 3. 去掉了visited数组，访问过的节点用'#'标注

struct TrieNode {
    string word;
    vector<TrieNode*> children;
    TrieNode() : children(26) {
        this->word = "";
    }   
};

void insertTrie(TrieNode * root,const string & word) {
    TrieNode * node = root;
    for (auto c : word){
        if (node->children[c - 'a'] == nullptr) {
            node->children[c - 'a'] = new TrieNode();
        }
        node = node->children[c - 'a'];
    }
    node->word = word;
}

class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * root, vector<string> & res) {
        char ch = board[x][y];        
        if (root->children[ch - 'a'] == nullptr) {
            return false;
        }
        root = root->children[ch - 'a'];
        if (root->word.size() > 0) {
            res.push_back(root->word);
            root->word = "";
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#') {
                    dfs(board, nx, ny, root,res);
                }
            }
        }
        board[x][y] = ch;

        return true;      
    }

    vector<string> findWords(vector<vector<char>> & board, vector<string> & words) {
        TrieNode * root = new TrieNode();
        vector<string> res;

        for (auto & word: words){
            insertTrie(root,word);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }        
        return res;        
    }
};