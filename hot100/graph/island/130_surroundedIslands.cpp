#include <vector>

using namespace std;

// 先把边上的岛屿置为 # ，再遍历数组，把#变成O，把O变成X

class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return;
        if(board[row][col] == 'O'){
            board[row][col] = '#';
            dfs(board, row-1, col);
            dfs(board, row+1, col);
            dfs(board, row, col+1);
            dfs(board, row, col-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if((i == 0 || i == m-1 || j == 0 || j == n-1 ) && board[i][j] == 'O'){
                    dfs(board, i, j);
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};


// 并查集 UnionFind
// 解决连通性问题
// 单独命名UnionFind时间效率会更高
class Solution{
public:
    vector<int> parents;

    void unite(int node1, int node2){
        int root1 = find(node1);
        int root2 = find(node2);
        if(root1 != root2)
            parents[root2] = root1;
    }

    int find(int node){
        while(parents[node] != node){
            parents[node] = parents[parents[node]];
            node = parents[node];
        }
        return node;
    }

    bool isConnected(int node1, int node2){
        return find(node1) == find(node2);
    }
    void solve(vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        
        int totalNum = m*n+1;
        parents.resize(totalNum);

        for(int i = 0; i < totalNum; ++i){
            parents[i] = i;
        }

        int dummyNode = m * n;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'O'){
                    if(i == 0 || i == m-1 || j == 0 || j == n-1)
                        unite(i*n + j, dummyNode);
                    else{
                        if(i > 0 && board[i-1][j] == 'O')
                            unite(i * n + j, (i - 1) * n + j);
                        if(i < m - 1 && board[i+1][j] == 'O')
                            unite(i * n + j, (i + 1) * n + j);
                        if(j > 0 && board[i][j-1] == 'O')
                            unite(i * n + j, i * n + (j - 1));
                        if(j < n - 1 && board[i][j+1] == 'O')
                            unite(i * n + j, i * n + (j + 1));
                    }
                }
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(isConnected(i * n + j, dummyNode))
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }

    }

};