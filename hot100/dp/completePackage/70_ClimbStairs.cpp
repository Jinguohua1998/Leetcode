//动态规划的空间复杂度简化
//O(n)的空间简化为O(1)
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n;
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};


#include <vector>

using namespace std;

//可以用多重背包的思路理解
//排列问题：先遍历背包后遍历物品
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) { // 遍历背包
            for (int j = 1; j <= 2; j++) { // 遍历物品
                if (i >= j) 
                    dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};