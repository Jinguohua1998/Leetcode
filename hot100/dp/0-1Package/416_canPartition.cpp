//0-1背包问题
//物品一个一个选，容量也一点一点增加去考虑
#include <vector>

using namespace std;

//空间复杂简化
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if((sum & 1) == 1)
            return false;
        int target = sum / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        if(nums[0] <= target)
            dp[nums[0]] = true;
        for(int i = 1; i < n; ++i){
            if(dp[target])
                return true;
            for(int j = target; nums[i] <= j; --j)
                dp[j] = dp[j] || dp[j - nums[i]];  // 注意：这里要用 ||  
        }
        return dp[target];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int num : nums){
            sum += num;
        }

        if((sum & 1) == 1){
            return false;
        }

        int target = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        dp[0][0] = true;

        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= target; ++j){
                if(nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else    
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
            if(dp[i][target])
                return true;
        }
        return dp[n][target];
    }
};

