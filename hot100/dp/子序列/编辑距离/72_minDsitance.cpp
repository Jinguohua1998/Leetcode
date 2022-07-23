#include <string>
#include <vector>
#include <climits>

using namespace std;

//动态规划
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        
        // 初始化操作不能忘了
        for (int i = 0; i <= word1.size(); i++) 
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) 
            dp[0][j] = j;
        
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min((dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};


//执行插入操作，那么比较word1[0,i]和word2[0,j-1]的结果
//执行删除操作，那么比较word1[0,i-1]和word2[0,j]的结果
//执行替换操作，那么比较word1[0,i-1]和word2[0,j-1]的结果
//选择上述三个选项中最小的那个加1

//递归法，大量重复运算，超时
class Solution {
public:
    int minDistance(string word1, string word2) {
//首先定义递归的结束条件
        if(word1.size() == 0 || word2.size() == 0)
            return max(word1.size(), word2.size());
//如果word1是空字符串，则执行若干次插入操作
//如果word2是空字符串，则执行若干次删除操作
        if(word1.back() == word2.back())
            return minDistance(word1.substr(0, word1.length()-1), word2.substr(0, word2.length()-1));
        else
            return 1 + min(
                minDistance(word1, word2.substr(0, word2.length() - 1)),
//插入操作
                min(
                    minDistance(word1.substr(0, word1.size() - 1), word2),
//删除操作
                    minDistance(word1.substr(0, word1.size() - 1), word2.substr(0, word2.size() - 1))
//替换操作
                )
            );
    }
};

//递归的改进版本——记忆化搜索
class Solution {
public:

    int minDistance (string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> res(m+1, vector<int>(n+1, -1));
        res[0][0] = 0;
        for(int i = 1; i <= m; ++i)
            res[i][0] = i;
        for(int i = 1; i <= n; ++i)
            res[0][i] = i;
        return solve(word1, word2, m, n, res);
    }

private:
    int solve(string& word1, string& word2, int len1, int len2, vector<vector<int>>& res){
        if(len1 == 0)
            return res[0][len2];
        if(len2 == 0)
            return res[len1][0];
        if (res[len1][len2] != -1)
        {
            return res[len1][len2];
        }
        if(word1[len1-1] == word2[len2-1])
//注意这里是len1-1，len2-1而不是len1，len2
            res[len1][len2] = solve(word1, word2, len1-1, len2-1, res);
        else
            res[len1][len2] = 1+min(
                                solve(word1, word2, len1, len2-1, res),
                                min(
                                    solve(word1, word2, len1-1, len2-1, res),
                                    solve(word1, word2, len1-1, len2, res)
                                ));
        return res[len1][len2];
        
    }
};


