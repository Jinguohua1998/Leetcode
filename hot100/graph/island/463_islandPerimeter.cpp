#include <vector>

using namespace std;

// 岛屿的边长总和
// 用迭代法更简单

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return 1;
        }else if(grid[row][col] == 0){
            return 1;
        }else if(grid[row][col] == 2){
            return 0;
        }else{
            grid[row][col] = 2;
            return dfs(grid, row+1, col) + dfs(grid, row-1, col) +
                    dfs(grid, row, col+1) + dfs(grid, row, col-1);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
};