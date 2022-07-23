// 本题与 lc10 非常类似，但相比较而言，本题稍微容易一些。
// 因为在本题中，模式 p 中的任意一个字符都是独立的，即不会和前后的字符互相关联，形成一个新的匹配模式。

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        // 要注意处理初始条件 ： 空字符串和空正则情况

        // 先解决空字符串的问题（重点注意）,也可以放到大的循环里面
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i){
            if(p[i-1] == '*')
                dp[0][i] = true;
            else
                break;
        }
        // 以下是非空字符串的问题
        for (int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
                else if(p[j-1] == '?' || s[i-1] == p[j-1])
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};