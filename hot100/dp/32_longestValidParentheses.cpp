#include <string>
#include <vector>
#include <stack>

using namespace std;

//动态规划法
//动态规划最好不要用int数组，而是用vector
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int res = 0;
//dp[i]存储的是以第i个字符结尾的字符串的最长匹配个数
        for(int i = 1; i < n; ++i){
            if(s[i] == '(')
                continue;
            else{
                if(s[i-1] == '(')
                    dp[i] = i >= 2 ? dp[i-2]+2 : 2;
                else if( i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '(' )
//如果此时用的是dp数组而不是vector可能会无法给某些元素无法赋值(是任意值)
//所以动态规划最好用vector
                    dp[i] = dp[i-1] + (i-dp[i-1] >= 2 ? dp[i-dp[i-1]-2] : 0) + 2;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

//栈
//栈底元素是上一个没有被匹配的右括号
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '(')
                stk.push(i);
            else{
                stk.pop();
                if(stk.empty())
                    stk.push(i);
                else
                    res = max(res, i - stk.top());
            }
        }
        return res;
    }
};

//双指针法
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, res = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            if(s[i] == '(')
                ++left;
            if(s[i] == ')')
                ++right;
            if(left ==  right)
                res = max(res, right*2);
            else if(right > left){
                left = 0;
                right = 0;
            }
        }

        left = right = 0;
        for(int i = n-1; i >= 0; --i){
            if(s[i] == '(')
                ++left;
            if(s[i] == ')')
                ++right;
            if(left ==  right)
                res = max(res, right*2);
            else if(right < left){
                left = 0;
                right = 0;
            }
        }
        return res;
    }
};