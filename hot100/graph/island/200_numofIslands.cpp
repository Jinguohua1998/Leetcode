//图算法，应该与树的遍历算法联系起来（BFS, DFS）
#include <vector>
#include <utility>
#include <queue>

using namespace std;

//DFS
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j){
        if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, m, n, i+1, j);
        dfs(grid, m, n, i, j+1);
        dfs(grid, m, n, i-1, j);
        dfs(grid, m, n, i, j-1);

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    ++res;
                    dfs(grid, m, n, i, j);
                }
            }
        }    
        return res;
    }
};

//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    bfs(grid, m, n, i, j);
                    ++count;
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>>& grid, int m, int n, int i, int j){
        queue<pair<int, int>> Q;
        Q.push({i, j});
        while(!Q.empty()){
            auto point = Q.front();
            Q.pop();
            int x = point.first, y = point.second;
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1'){
                grid[x][y] = '0';
                Q.push({x-1, y});
                Q.push({x+1, y});
                Q.push({x, y-1});
                Q.push({x, y+1});
            }
        }
    }
};

