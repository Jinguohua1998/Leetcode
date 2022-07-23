// 有重复项
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) 
                r = m;
            else if(nums[m] > nums[r])
                l = m + 1;
            else    // 去重
                --r;
        }
        return nums[l];
    }
};