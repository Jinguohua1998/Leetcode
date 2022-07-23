//双指针法
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0;
        // left是0与非0的边界
        for(int right = 0; right < n; ++right){
            if(nums[right] != 0){
                if(right != left)
                    swap(nums[left], nums[right]);
                ++left;
            }
        }
    }
};