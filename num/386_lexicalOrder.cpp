/*
给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。

你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。

 

示例 1：

输入：n = 13
输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]

*/
#include <bits/stdc++.h>

using namespace std;

// 递归法
class Solution {
public:
    vector<int> res;
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; ++i) dfs(i, n);
        return res;
    }
    void dfs(int cur, int limit) {
        if (cur > limit) return;
        res.push_back(cur);
        for(int i = 0; i <= 9; ++i) dfs(cur * 10 + i, limit);
    }
};

// 迭代法
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int number = 1;
        for (int i = 0; i < n; i++) {
            ret[i] = number;
            if (number * 10 <= n) {
                number *= 10;
            } else {
                while (number % 10 == 9 || number + 1 > n) {
                    number /= 10;
                }
                number++;
            }
        }
        return ret;
    }
};
