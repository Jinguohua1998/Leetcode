#include <vector>

using namespace std;

// 掷骰子n次，点数之和的出现的概率

// 动态规划（节省空间版本）

class Solution{
public:
    vector<double> dicesProbability(int n){
        vector<double> dp(6, 1.0/6.0);
        for(int k = 2; k <= n; ++k){
            vector<double> tmp(dp.size() + 5, 0.0);
            for(int i = 0; i < dp.size(); ++i){
                for(int j = 0; j < 6; ++j){
                    tmp[i + j] += dp[i]/6.0;
                }
            }
            dp = tmp;
        }
        return dp;
    }
};