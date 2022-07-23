//思路类似于lc 647
#include <string>
#include <vector>
#include <utility>
//std::pair,std::make_pair

using namespace std;

//动态规划(状态转移方程),也可以称作双指针法
class Solution {
    public:
        string longestPalindrome(string s){
            int n = s.length();
            int maxLen = 0;
            int start;
            vector<vector<bool>>dp(n, vector<bool>(n, false));
            for(int j = 0; j < n; ++j){//右指针
                for(int i = 0; i <= j; ++i){//左指针
                    if(s[i] == s[j] && (j - i <= 1 || dp[i+1][j-1])){
                        dp[i][j] = true;
                        if(j - i + 1 > maxLen){
                            maxLen = j - i + 1;
                            start = i;
                        }
                            
                    }
                }
            }
            return s.substr(start, maxLen);
        }
};

//中心扩展法，回文字符串的长度分为偶数和奇数
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        int start;
        for(int i = 0; i < 2*n-1; ++i){
            int left = i/2, right = i/2+i%2;
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 > maxLen){
                    maxLen = right - left + 1;
                    start = left;
                }
                --left;
                ++right;
            }
        }
        return s.substr(start, maxLen);
    }
};