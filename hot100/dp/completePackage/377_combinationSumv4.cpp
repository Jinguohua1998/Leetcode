#include <vector>
#include <climits>

using namespace std;

//本题与动态规划: lc 518零钱兑换II 是一个鲜明的对比，一个是求排列，一个是求组合，遍历顺序完全不同

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) { // 遍历背包
            for (int j = 0; j < nums.size(); j++) { // 遍历物品
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
//自动舍弃结果超过INT_MAX的dp元素
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};