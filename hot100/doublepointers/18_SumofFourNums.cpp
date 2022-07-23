#include <vector>
#include <algorithm>

using namespace std;
// 这题有三处去重，i去重，j去重，left和right去重
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j < n; ++j){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
//这里的去重千万不能忘了
                int left = j+1;
                int right = n-1;
                while(left < right){
                    if(nums[i]+nums[j] < target - (nums[left]+nums[right]))
                        ++left;
                    else if(nums[i] + nums[j]  > target - (nums[left] + nums[right]))
                        --right;
                    else{
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1])
                            ++left;
                        while(left < right && nums[right] == nums[right-1])
                            --right;
                        --right;
                        ++left;
                    }
                }
            }
        }
        return res;
    }
};