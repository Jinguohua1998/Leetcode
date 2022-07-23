#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
//不可以用贪心算法
//每次尽量取最大的coin，最后的总数有可能不是最少

//完全背包问题
//这一题两种遍历方法都可以，首选先遍历物品再遍历背包
// 本题是要求最少硬币数量，硬币是组合数还是排列数都无所谓！所以两个for循环先后顺序怎样都可以！
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) { // 遍历物品
            for (int j = coins[i]; j <= amount; j++) { // 遍历背包
                if (dp[j - coins[i]] != INT_MAX) { // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }
//考虑无法匹配的情况
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};

//记忆化搜索(类似于递归)
class Solution{

    vector<int> count;

    int dp(vector<int>& coins, int rem){
        if(rem < 0)
            return -1;
        if(rem == 0)
            return 0;
        if(count[rem-1] != 0)
            return count[rem-1];
        int Min = INT_MAX;
        for(int coin : coins){
            int res = dp(coins, rem - coin);
            if(res >= 0 && res < Min)
                Min = res + 1;
        }
        count[rem-1] = Min == INT_MAX ? -1 : Min;
        return count[rem - 1];
        
    }

    public:
        int coinChange(vector<int>& coins, int amount){
            if(amount < 1)
                return 0;
            count.resize(amount);
            return dp(coins, amount);
        }
};