#include <string>
#include <vector>

using namespace std;

// 用动态规划解决，等效于矩阵中的不同路径
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(s3.size() != n+m)
            return false;
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        dp[0][0] = true;
        //初始化
        for(int i = 1; i <= m && s1[i-1] == s3[i-1]; ++i)
            dp[i][0] = true;
        for(int j = 1; j <= n && s2[j-1] == s3[j-1]; ++j)
            dp[0][j] = true;
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = (dp[i-1][j] && s3[i+j-1] == s1[i-1]) 
                        || (dp[i][j-1] && s3[i+j-1] == s2[j-1]);
            }
        }
        return dp[m][n];
    }
};

// 也可以尝试空间复杂度更小的解法