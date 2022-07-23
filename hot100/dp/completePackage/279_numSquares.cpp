#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// 思路同lc 322零钱兑换，求的是最小组合数，所以两种遍历方式均可
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) { // 遍历背包
            for (int j = 1; j * j <= i; j++) { // 遍历物品
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};