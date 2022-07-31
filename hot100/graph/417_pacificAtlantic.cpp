#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1}; // 保存四个方向

    // 从低向高遍历，注意这里visited是引用，即可以改变传入的pacific和atlantic的值
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y]) return;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) { // 向四个方向遍历
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            // 超过边界
            if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size()) continue;
            // 高度不合适，注意这里是从低向高判断
            if (heights[x][y] > heights[nextx][nexty]) continue;

            dfs (heights, visited, nextx, nexty);
        }
        return;

    }

public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int n = heights.size();
        int m = heights[0].size(); // 这里不用担心空指针，题目要求说了长宽都大于1

        // 记录从太平洋边出发，可以遍历的节点
        vector<vector<bool>> pacific = vector<vector<bool>>(n, vector<bool>(m, false));

        // 记录从大西洋出发，可以遍历的节点
        vector<vector<bool>> atlantic = vector<vector<bool>>(n, vector<bool>(m, false));

        // 从最上最下行的节点出发，向高处遍历
        for (int i = 0; i < n; i++) {
            dfs (heights, pacific, i, 0); // 遍历最上行，接触太平洋
            dfs (heights, atlantic, i, m - 1); // 遍历最下行，接触大西洋
        }

        // 从最左最右列的节点出发，向高处遍历
        for (int j = 0; j < m; j++) {
            dfs (heights, pacific, 0, j); // 遍历最左列，接触太平洋
            dfs (heights, atlantic, n - 1, j); // 遍历最右列，接触大西洋
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 如果这个节点，从太平洋和大西洋出发都遍历过，就是结果
                if (pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
};
