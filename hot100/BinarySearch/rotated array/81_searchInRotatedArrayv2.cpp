// 有重复项
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r){
            int m = l + (r - l)/2;
            if(nums[m] == target)
                return true;
            // 去重 
            if(nums[m] == nums[l] && nums[m] == nums[r]){
                ++l;
                --r;
            }else if(nums[m] > nums[r]){
                if(nums[m] > target && nums[l] <= target)
                    r = m - 1;
                else    
                    l = m + 1;
            }else{
                if(nums[m] < target && nums[r] >= target)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return false;
    }
};