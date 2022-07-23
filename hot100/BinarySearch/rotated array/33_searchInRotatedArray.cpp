#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n -1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] == target)
                return m;
            if(nums[m] > nums[r]){
                if(nums[m] > target && nums[l] <= target)
                // 第二个判断条件要注意
                    r = m - 1;
                else
                    l = m + 1;
            }else{
                if(nums[m] < target && nums[r] >= target)
                // 第二个判断条件要注意
                    l = m + 1;
                else    
                    r = m - 1;
            }
        }
        return -1;
    }
};