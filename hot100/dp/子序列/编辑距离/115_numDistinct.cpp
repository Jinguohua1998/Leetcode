#include <string>
#include <vector>

using namespace std;

// lc 392是判断子序列，而这里是计算子序列的个数
//dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<uint64_t>> dp(m + 1, vector<uint64_t>(n + 1));
        for (int i = 0; i < s.size(); i++) 
            dp[i][0] = 1;
        for (int j = 1; j < t.size(); j++) 
            dp[0][j] = 0;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};