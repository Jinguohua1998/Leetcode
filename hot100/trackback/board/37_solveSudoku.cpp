#include <vector>
#include <bitset>

using namespace std;

class Solution {
private:
    bool backtrack(vector<vector<char>>& board){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.')
                    continue;
                for(char k = '1'; k <= '9'; ++k){
                    if(isValid(board, i, j, k)){
                        board[i][j] = k;
                        if(backtrack(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char val){
        for(int i = 0; i < 9; ++i){
            if(board[i][col] == val)
                return false;
        }
        for(int j = 0; j < 9; ++j){
            if(board[row][j] == val)
                return false;
        }
        int startRow = row/3*3;
        int startCol = col/3*3;
        for(int i = startRow; i < startRow+3; ++i){
            for(int j = startCol; j < startCol+3; ++j){
                if(board[i][j] == val)
                    return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};