#include <iostream>
#include <vector>

using namespace std;

//更简洁的写法
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            while(nums[i] != 0){
                if(nums[nums[i]] == nums[i])
                    return nums[i];
                else
                    swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
