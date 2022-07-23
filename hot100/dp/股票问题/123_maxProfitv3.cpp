//只能买卖两次
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

//动态规划

//可以简化为5个状态
//0 不持有股票，没有卖出过
//1 持有股票，没有卖出过
//2 不持有股票，卖出过一次
//3 持有股票，卖出过一次
//4 不持有股票，卖出过两次
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int n = prices.size();
        int dp[n][5];
//用数组不会初始化为0，但是空间利用率高
        dp[0][0] = dp[0][2] = dp[0][4] = 0;
//没有买入的情况下，卖出的收益为零，dp[0][2] = dp[0][4] = 0
        dp[0][1] = dp[0][3]= -prices[0];
//dp[0][3] = -prices[0]假设全程只进行一次交易，最后就不用进行max比较
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }
        return dp[n-1][4];
    }
};


// 空间简化
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<int> dp(5, 0);
        dp[1] = -prices[0];
        dp[3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[4] = max(dp[4], dp[3] + prices[i]);
        }
        return dp[4];
    }
};