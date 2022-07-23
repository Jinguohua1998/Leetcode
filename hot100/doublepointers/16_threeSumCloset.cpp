// 思路与lc 15三数之和相同
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n; ++i){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i+1, right = n-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(target == sum)
                    return sum;
                if(abs(sum-target) < abs(res-target))
                    res = sum;
                if(sum < target)
                    ++left;
                else
                    --right;
            }
        }
        return res;
    }
};