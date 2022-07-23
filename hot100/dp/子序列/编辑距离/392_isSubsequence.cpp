#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool sequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        // dp的含义：dp[i][j] t[j]结尾的字符串中在s[i]结尾字符串出现的个数
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = dp[i][j - 1]; 
                    // 这里的s的每一个字符都要匹配，所以是dp[i][j] = dp[i][j-1]而不是dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            }
        }
        if (dp[s.size()][t.size()] == s.size()) 
            return true;
        return false;
    }
};