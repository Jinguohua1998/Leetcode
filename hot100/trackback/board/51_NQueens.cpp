//与lc37数独问题类似
#include <string>
#include <vector>

using namespace std;

//效率更高的解法
class Solution {

private:
vector<vector<string>> result;
vector<string> board;

// n 为输入的棋盘大小
// row 是当前递归到***的第几行了
void backtrack(int n, int row) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(n, row, col)) { // 验证合法就可以放
            board[row][col] = 'Q'; // 放置皇后
            backtrack(n, row + 1);
            board[row][col] = '.'; // 回溯，撤销皇后
        }
    }
}
bool isValid(int n, int row, int col) {
    // 检查列
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    // 检查 45度角是否有皇后
    for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    // 检查 135度角是否有皇后
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        board.resize(n, string(n, '.'));
        backtrack(n, 0);
        return result;
    }
};
