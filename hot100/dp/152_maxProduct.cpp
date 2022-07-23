//题型和lc53 类似
#include <vector>

using namespace std;

// 动态规划
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], res = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int mx = maxF, mn = minF;
            maxF = max(mx*nums[i], max(nums[i], mn*nums[i]));
            minF = min(mn*nums[i], min(nums[i], mx*nums[i]));
            res = max(res, maxF);
        }
        return res; 
    }
};