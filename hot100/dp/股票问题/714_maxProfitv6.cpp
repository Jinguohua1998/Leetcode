//有手续费
#include <vector>

using namespace std;
//贪心算法，类似于lc122
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0;
        int minPrice = prices[0];
        int n = prices.size();
        for(int i = 1; i < n; ++i){
            if(prices[i] < minPrice)
                minPrice = prices[i];
            if(prices[i] >= minPrice && prices[i] <= minPrice+fee)
                continue;
            if(prices[i] > minPrice + fee){
                res += prices[i] - (minPrice+fee);
                minPrice = prices[i] - fee;
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = prices[0] + fee;
        int profit = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] + fee < buy) {
                buy = prices[i] + fee;
            }
            else if (prices[i] > buy) {
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return profit;
    }
};


//动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
