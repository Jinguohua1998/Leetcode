#include <bits/stdc++.h>

using namespace std;

/*
先对宽度 w 进行升序排序，如果遇到 w 相同的情况，则按照高度 h 降序排序。
之后把所有的 h 作为一个数组，在这个数组上计算 LIS （最长递增子序列）的长度就是答案

可以用动态规划也可以用贪心+二分查找
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty())
            return 0;

        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2){
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        vector<int> dp = {envelopes[0][1]}; // dp[i]表示长度为i的递增字符串最后一个元素的最小数值
        for(int i = 1; i < n; ++i){
            if(envelopes[i][1] > dp.back())
                dp.push_back(envelopes[i][1]);
            else{   // 二分查找
                auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        return dp.size();
    }
};