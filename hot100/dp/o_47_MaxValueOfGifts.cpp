#include <vector>
#include <algorithm>

using namespace std;

class Solution1{
    public:
        int maxValue(vector<vector<int>>& gift){
            int rows = gift.size(), cols = gift[0].size();
//也可以不定义vector，直接使用传入的gift 
            vector<vector<int>> dp(rows, vector<int>(cols, 0));
            dp[0][0] = gift[0][0];
            for(int i = 1; i < rows; ++i){
                dp[i][0] += gift[i][0]+dp[i-1][0];
            }
            for(int i = 1; i < cols; ++i){
                dp[0][i] += gift[0][i]+dp[0][i-1];
            }
            for(int i = 1; i < rows; ++i){
                for(int j = 1; j < cols; ++j){
                    dp[i][j] += max(dp[i-1][j], dp[i][j-1]) + gift[i][j];
                }
            }
            return dp[rows-1][cols-1];
        }
};

//节省内存使用空间（滚动数组法——给空间复杂度「降维」）
class Solution2{
    public:
        int maxValue(vector<vector<int>>& gift){
            int rows = gift.size();
            int cols = gift[0].size();
            vector<int> dp(cols, -1);
            for(int i = 0; i < rows; ++i){
                for(int j = 0; j < cols; ++j){
                    int left = 0;
                    int up = 0;
                    if(i > 0)
                        up = dp[j];
                    if(j > 0)
                        left = dp[j-1];
                    dp[j] = max(up, left) + gift[i][j];

                }
            }
            return dp[cols-1];
        }
};