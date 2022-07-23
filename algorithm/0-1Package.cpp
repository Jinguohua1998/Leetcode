#include <vector>

using namespace std;

class Solution{
    int maxValue(vector<int>& weight, vector<int>& value, int bagWeight){
        int m = value.size();
        int n = bagWeight;
        vector<vector<int>> dp(m, vector<int>(n + 1, 0));
//dp的i表示物品的索引，j表示重量，dp[i][j]表示遍历到第i个物品时，背包重量为j时的最大物品价值

//dp数组的初始化
        for(int i = bagWeight; i >= weight[0]; --i){
            dp[0][i] = value[0];
        }

//先遍历物品，再遍历背包的重量
        for(int i = 1; i < m; ++i){
            for(int j = 0; j <= bagWeight; ++j){
                if(j < weight[i])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
            }
        }
        return dp[m-1][n];
    }
};

//dp简化为一维数组
//这里要要注意遍历顺序（从尾到头而不是从头到尾）
class Solution{
    int maxValue(vector<int>& weight, vector<int>& value, int bagWeight){
        int m = weight.size();
        int n = bagWeight;
        vector<int> dp(n+1, 0);
        for(int j = weight[0]; j <= n; ++j)
            dp[j] = value[0];
        for(int i = 1; i < m; ++i){
//注意这里的遍历顺序
            for(int j = bagWeight; j >=0; --j){
                if(j >= weight[i])
                    dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
            }
        }
        return dp.back();
    }
};

