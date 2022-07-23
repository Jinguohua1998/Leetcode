#include <vector>
#include <cstring>

using namespace std;

//思路类似于lc300

// 删除单调坡度上的节点（不包括单调坡度两端的节点）
// 不用记录上一个爬坡的数字，只用记录差值
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int curDiff = 0;
        int preDiff = 0;
        int res = 1;
        for(int i = 0; i < nums.size()-1; ++i){
            curDiff = nums[i+1] - nums[i];
            if((curDiff < 0 && preDiff >= 0) || (curDiff > 0 && preDiff <= 0)){
                ++res;
                preDiff = curDiff; // 要放在if条件判断语句里面，防止会出现 0 1 1 2这种情况
            }
        }
        return res;
    }
};

//动态规划
//设dp状态dp[i][0]，表示考虑前i个数，第i个数作为山峰的摆动子序列的最长长度
//设dp状态dp[i][1]，表示考虑前i个数，第i个数作为山谷的摆动子序列的最长长度

class Solution {
public:
    int dp[1005][2];
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] > nums[i]) 
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i]) 
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};