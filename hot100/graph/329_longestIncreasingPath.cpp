#include <bits/stdc++.h>

using namespace std;

// 记忆化搜索

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo){
        int m = matrix.size();
        int n = matrix[0].size();
        if(memo[i][j] != 1)
            return memo[i][j];
        if(i > 0 && matrix[i][j] < matrix[i-1][j]){
            memo[i][j] = max(memo[i][j], 1 + dfs(i-1, j, matrix, memo));
        }
        if(i < m-1 && matrix[i][j] < matrix[i+1][j]){
            memo[i][j] = max(memo[i][j], 1 + dfs(i + 1, j, matrix, memo));
        }
        if(j > 0 && matrix[i][j] < matrix[i][j-1]){
            memo[i][j] = max(memo[i][j], 1 + dfs(i, j - 1, matrix, memo));
        }
        if(j < n-1 && matrix[i][j] < matrix[i][j+1]){
            memo[i][j] = max(memo[i][j], 1 + dfs(i, j + 1, matrix, memo));
        }
        return memo[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 1;
        vector<vector<int>> memo(m, vector<int>(n, 1));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                res = max(res, dfs(i, j, matrix, memo));
            }
        }
        return res;
    }
};