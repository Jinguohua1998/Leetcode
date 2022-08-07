/*
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。

*/
//一次遍历
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(auto num : nums){
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> res;
        for(int i = 0; i < n; ++i){
            if(nums[i] <= n){
                res.push_back(i+1);
            }
        }
        return res;
    }
};