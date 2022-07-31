/*
峰值元素是指其值严格大于左右相邻值的元素。
给你一个整数数组 nums，找到峰值元素并返回其索引。
数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
你可以假设 nums[-1] = nums[n] = -∞ 。
nums[i] != nums[i + 1]
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while( l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[mid + 1]) 
                r = mid;
            else 
                l = mid + 1;
        }
        return r;
    }
};