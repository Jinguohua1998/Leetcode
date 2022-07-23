#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 两遍DFS 
// 第一遍 ： 遍历陆地格子，计算每个岛屿的面积并标记岛屿
// 第二遍 ： 遍历海洋格子，观察每个海洋格子相邻的陆地格子
class Solution {
public:
    int area(vector<vector<int>>& grid, int row, int col, int index){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || grid[row][col] == index)
            return 0;
        else {
            grid[row][col] = index;
            return 1 + area(grid, row+1, col, index) + area(grid, row-1, col, index)
                    + area(grid, row, col+1, index) + area(grid, row, col-1, index);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int index = 2;
        unordered_map<int, int> indexAndArea;
        int res = 1;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    indexAndArea[index] = area(grid, i, j, index);
                    res = max(res, indexAndArea[index]);
                    ++index;
                }
            }
        } 
        
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 0){
                    unordered_set<int> hashSet = findNeighbors(grid, i, j);
                    
                    if(hashSet.size() < 1)
                        continue;
                    int area = 1;
                    for(auto idx : hashSet){
                        area += indexAndArea[idx];
                    }
                    res = max(res, area);
                }
            }
        }    
        
        return res;
        
    }
    unordered_set<int> findNeighbors(vector<vector<int>>& grid, int row, int col){
        unordered_set<int> res;
        if(row > 0 && grid[row-1][col] > 1)
            res.insert(grid[row-1][col]);
        if(row < grid.size()-1 && grid[row+1][col] > 1)
            res.insert(grid[row+1][col]);
        if(col > 0 && grid[row][col-1] > 1)
            res.insert(grid[row][col-1]);
        if(col < grid[0].size()-1 && grid[row][col+1] > 1)
            res.insert(grid[row][col+1]);
        return res;
    }
};