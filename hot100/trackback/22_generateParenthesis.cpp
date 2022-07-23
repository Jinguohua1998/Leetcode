#include <vector>
#include <string>
#include <memory>

using namespace std;

//回溯法，这一题和HW进出火车站比较像
class Solution1 {
    void backtrack(vector<string>& res, string& cur, int open, int close, int n){
        if(cur.length() == n * 2){
            res.push_back(cur);
            return ; 
        }

        if(open < n){
            cur.push_back('(');
            backtrack(res, cur, open+1, close, n);
            cur.pop_back();
//剪枝：pop_back是回溯法的关键步骤（DFS）
        }

        if(close < open){
            cur.push_back(')');
            backtrack(res, cur, open, close+1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        backtrack(res, cur, 0, 0, n);
        return res;
    }
};

//动态规划
//第一种理解
//对于n，相较于n-1，多了一个()
//剩下的括号要么在这一组新增的括号内部，要么在这一组新增括号的外部（右侧）。
//"(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】
//其中 p + q = n-1，且 p q 均为非负整数。

//第二种理解
//任何一个括号序列都一定是由 ( 开头，并且第一个 ( 一定有一个唯一与之对应的 )。
//这样一来，每一个括号序列可以用 (a)b 来表示，其中 a 与 b 分别是一个合法的括号序列（可以为空）。

class Solution2 {
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return {};
        if(n == 1)
            return {"()"};
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
//如果dp[0] = {},则代表vector内容为空，dp[0] = {""}，则代表vector有一个空字符串，不一样
        dp[1] = {"()"};
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j <= i-1; ++j){
                int k = i-1-j;
                for(auto s1 : dp[j]){
                    for(auto s2 : dp[k]){
                        dp[i].push_back("("+s1+")"+s2);
                    }
                }

            }
        }
        return dp[n];
    }
};

//递归法
class Solution {
    shared_ptr<vector<string>> cache[100] = {nullptr};
public:
    shared_ptr<vector<string>> generate(int n) {
        if (cache[n] != nullptr)
            return cache[n];
        if (n == 0) {
            cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        } else {
            auto result = shared_ptr<vector<string>>(new vector<string>);
            for (int i = 0; i != n; ++i) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string& left : *lefts)
                    for (const string& right : *rights)
                        result -> push_back("(" + left + ")" + right);
            }
            cache[n] = result;
        }
        return cache[n];
    }
    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }
};
