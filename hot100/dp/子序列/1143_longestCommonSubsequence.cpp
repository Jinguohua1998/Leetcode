#include <string>
#include <vector>

using namespace std;

// 最长公共子序列（和lc718不同，子序列不要求连续）

//dp[i][j]:长度为[0,i-1]的字符串text1与长度为[0,j-1]的字符串text2的最长公共子序列长度
//注意，这里不是以i-1/j-1结尾
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
