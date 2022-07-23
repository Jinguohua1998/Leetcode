#include <vector>

using namespace std;

//双指针法
//类似的还有lc11 max area
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            int i = 0, j = nums.size() - 1;
            while(i < j){
                int sum = nums[i] + nums[j];
                if(sum == target)
                    return {nums[i], nums[j]};
                else if(sum < target)
                    ++i;
                else if(sum > target)
                    --j;

            }
            return {};
        }
};