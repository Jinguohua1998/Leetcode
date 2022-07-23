// 和lc 44类似，用动态规划解决
// 遇到这种情况一定要考虑边界条件，也就是i == 0和j == 0的情况
#include <string>
#include <vector>

using namespace std;

//https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/zhu-xing-xiang-xi-jiang-jie-you-qian-ru-shen-by-je/
class Solution {
    public:
        bool isMatch(string s, string p){
            int m = s.length();
            int n = p.length();
            vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
            for(int i = 0; i <= m; ++i){
//判断以第i个字符结尾的s与第j个字符结尾的p的匹配
                for(int j = 0; j <= n; ++j){
//i是文本字符串索引，j是匹配字符串索引
//分成空正则和非正则两种
//j == 0表示没有正则表达式，而不是对应p[0]，i同理，（类似于0-1背包问题）
                    if(j == 0)
                        dp[i][j] = (i == 0); // 这里不能单独初始化dp[0][0]， 因为考虑到正则表达式ch*也可以匹配空字符串
                    else{
//非空正则分为*和非*
                        if(p[j-1] != '*'){
                            if( i >= 1 && (p[j-1] == s[i-1] || p[j-1] == '.') )
                                dp[i][j] = dp[i-1][j-1] | dp[i][j];
                        }else if(j >= 2){
//碰到 * 了，分为看和不看两种情况
//不看*以及它前面的字母
                            dp[i][j] = dp[i][j-2] | dp[i][j];
//看*以及它前面的字母
                            if(i >= 1 && (s[i-1] == p[j-2] || p[j -2] == '.'))
                                dp[i][j] = dp[i-1][j] | dp[i][j];
                        }  
                    }    
                }
            }
            return dp[m][n];
        }
};