/*
给你一个整数数组 nums 和一个整数 k 。 nums 仅包含 0 和 1 。
每一次移动，你可以选择 相邻 两个数字并将它们交换。
请你返回使 nums 中包含 k 个 连续 1 的 最少 交换次数。
*/
#include <bits/stdc++.h>

using namespace std;

// 用滑动窗口解决，滑动窗口内部，可以用中位数或者zeros数组解决

// 中位数
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        int n = nums.size();
        vector<int> g;
        vector<int> sum = {0};
        int count = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                ++count;
                g.push_back(i - count);
                sum.push_back(sum.back() + g.back());
            }
        }
        
        int m = g.size();
        int ans = INT_MAX;
        for (int i = 0; i + k <= m; ++i) {
            int mid = (i + i + k - 1) / 2;
            int q = g[mid];
            ans = min(ans, (2 * (mid - i) - k + 1) * q + (sum[i + k] - sum[mid + 1]) - (sum[mid] - sum[i]));
        }
        
        return ans;
    }
};

// zeros数组
class Solution {
private:
    vector<int> zeros;
    vector<int> pre {0};
    
    // zeros[i]表示第i个1和第i+1个1之间0的个数
    void GenerateZeros(const vector<int> &nums) {
        int n = nums.size(), i = 0;
        while (i < n && nums[i] == 0) i++;
        while (i < n) {
            int j = i+1;
            while (j < n && nums[j] == 0) j++;
            if (j < n) zeros.push_back(j-i-1);
            i = j;
        }
    }
    
    void GeneratePresum(vector<int>& zeros) {
        for (int i = 0; i < zeros.size(); i++) {
            pre.push_back(pre.back() + zeros[i]);
        }
    }
    
    int GetRangeSum(int left, int right) {
        return pre[right+1] - pre[left];
    }
    
public:
    int minMoves(vector<int>& nums, int k) {
        GenerateZeros(nums);                        //第一步：生成zeros
        
        int cost = 0;                               //第二步：计算第一个窗口的解
        int left = 0, right = k-2;
        for (int i = left; i <= right; i++) {
            cost += zeros[i] * (min(i+1, right-i+1));
        }
        
        int minCost = cost;
        
        GeneratePresum(zeros);                      //第三步：开始滑动窗口
        int i = 1, j = i + k - 2;
        for (; j < zeros.size(); i++, j++) {
            int mid = (i + j) / 2;
            cost -= GetRangeSum(i-1, mid-1);
            cost += GetRangeSum(mid+k%2, j);
            minCost = min(minCost, cost);
        }
        
        return minCost;
    }
};
