//有冷冻期
#include <vector>

using namespace std;


//dp[i][0] 持有股票
//dp[i][1] 不持有股票，且处于冷冻期
//dp[i][2] 不持有股票，且不处于冷冻期
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int n = prices.size();
        int dp[n][3];
        dp[0][0] = -prices[0];
        dp[0][1] = dp[0][2] = 0;
        for(int i = 1; i < n; ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]-prices[i]);
//dp[i-1][2]-prices[i]不能写成dp[i-1][1]
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};

//节省空间方法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        for (int i = 1; i < n; ++i) {
            int newf0 = max(f0, f2 - prices[i]);
            int newf1 = f0 + prices[i];
            int newf2 = max(f1, f2);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }

        return max(f1, f2);
    }
};
