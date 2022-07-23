//同offer 12
//回溯法
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool trackback(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int i, int j, int k){
        if(k == word.size())
            return true;
        int m = board.size(), n = board[0].size();
        if(i >= 0 && i < m && j >= 0 && j < n 
            && visited[i][j] == false && board[i][j] == word[k]){
            visited[i][j] = true;
            ++k;
            bool flag = trackback(board, visited, word, i+1, j, k)||
                        trackback(board, visited, word, i, j+1, k)||
                        trackback(board, visited, word, i-1, j, k)||
                        trackback(board, visited, word, i, j-1, k);
            if(flag)
                return true;
            visited[i][j] = false;
            --k;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                bool flag = trackback(board, visited, word, i, j, 0);
                if(flag)
                    return true;
            }
        }
        return false;
    }
};