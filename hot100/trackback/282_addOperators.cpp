#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string path;
    vector<string> res;
    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0);
        return res;
    }
    void backtrack(const string& num, int target, int i, long ans, long mul){
        int n = num.size();
        if(i == n){
            if(ans == target)
                res.push_back(path);
            return;
        }
        // 占位，下面填充符号
        int signIndex = path.size();
        if(i > 0)   // 表达式开头不用添加符号，所以也不用push_back(0)
            path.push_back(0);

        long val = 0;
        // 注意数字可以是单个 0 但不能有前导零
        for (int j = i; j < n && (j == i || num[i] != '0'); ++j){
            val = val * 10 + num[j] - '0';
            path.push_back(num[j]);
            // 表达式开头不能添加符号
            if(i == 0){
                backtrack(num, target, j + 1, val, val);
            }else{
                path[signIndex] = '+';
                backtrack(num, target, j + 1, ans + val, val);
                path[signIndex] = '-';
                backtrack(num, target, j + 1, ans - val, -val);
                path[signIndex] = '*';
                backtrack(num, target, j + 1, ans - mul + mul * val, mul * val);
            }
        }
        // 剪枝操作
        path.resize(signIndex);
    }
};