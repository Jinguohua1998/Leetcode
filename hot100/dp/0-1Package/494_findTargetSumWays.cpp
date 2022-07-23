//背包问题(动态规划)，类似于lc 416
#include <vector>

using namespace std;

//动态规划
//减的数的和为neg，加的数的和为pos
//neg + pos = sum
//pos - neg = target

//空间复杂度降低的动态规划
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        int diff = sum - target;
        if(diff < 0 || diff % 2 != 0)
            return 0;
//要注意检查diff < 0的情况
        int neg = diff / 2;
        vector<int> dp(neg+1, 0);
        dp[0] = 1;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            for(int j = neg; j >= nums[i]; --j){
//内层循环需采用倒序遍历
                dp[j] += dp[j-nums[i]]; 
            }
        }
        return dp[neg];
    }
};


//回溯法
//在这个回溯法中没有剪枝操作，当传引用或者作为类中私有成员时需要剪枝
class Solution {
    int count = 0;
    void backtrack(vector<int>& nums, int target, int index, int sum ){
        if(index == nums.size() ){
            if(sum == target)
                ++count;
        }else{
            backtrack(nums, target, index + 1, sum + nums[index]);
            backtrack(nums, target, index + 1, sum - nums[index]);
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }

};

