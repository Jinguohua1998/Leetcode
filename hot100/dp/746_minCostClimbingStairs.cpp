#include <vector>

using namespace std;

// 最小代价爬楼梯

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1);
        dp[0] = dp[1] = 0;
        // 从第二级楼梯开始爬
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};