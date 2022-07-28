/*
给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。
你可以 按任意顺序 返回答案。
*/
#include<bits/stdc++.h>

using namespace std;

// 记忆化搜索 + 动态规划

class Solution {
public:
    const int ADDITION = -1;
    const int SUBTRACTION = -2;
    const int MULTIPLICATION = -3;

    vector<int> dfs(vector<vector<vector<int>>>& dp, int l, int r, const vector<int>& ops) {
        if (dp[l][r].empty()) {
            if (l == r) {
                dp[l][r].push_back(ops[l]);
            } else {
                for (int i = l; i < r; i += 2) {
                    auto left = dfs(dp, l, i, ops);
                    auto right = dfs(dp, i + 2, r, ops);
                    for (auto& lv : left) {
                        for (auto& rv : right) {
                            if (ops[i + 1] == ADDITION) {
                                dp[l][r].push_back(lv + rv);
                            } else if (ops[i + 1] == SUBTRACTION) {
                                dp[l][r].push_back(lv - rv);
                            } else {
                                dp[l][r].push_back(lv * rv);
                            }
                        }
                    }
                }
            }
        }
        return dp[l][r];
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ops;
        for (int i = 0; i < expression.size();) {
            if (!isdigit(expression[i])) {
                if (expression[i] == '+') {
                    ops.push_back(ADDITION);
                } else if (expression[i] == '-') {
                    ops.push_back(SUBTRACTION);
                } else {
                    ops.push_back(MULTIPLICATION);
                }
                i++;
            } else {
                int t = 0;
                while (i < expression.size() && isdigit(expression[i])) {
                    t = t * 10 + expression[i] - '0';
                    i++;
                }
                ops.push_back(t);
            }
        }
        vector<vector<vector<int>>> dp((int) ops.size(), vector<vector<int>>((int) ops.size()));
        return dfs(dp, 0, ops.size() - 1, ops);
    }
};