/*
动态规划的题目分为两大类，一种是求最优解类，典型问题是背包问题，另一种就是计数类，
比如这里的统计方案数的问题，它们都存在一定的递推性质。前者的递推性质还有一个名字，
叫做 「最优子结构」 ——即当前问题的最优解取决于子问题的最优解，后者类似，
当前问题的方案数取决于子问题的方案数。所以在遇到求方案数的问题时，我们可以往动态规划的方向考虑。
*/

//用滚动数组法进行空间复杂度简化

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<int> dp(cols, 0);
        dp[0] = 1;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else if(j >= 1){
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp.back();
    }
};

//空间复杂度更高，但是更清晰的解法
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};