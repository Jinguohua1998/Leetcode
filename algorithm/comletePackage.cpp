#include <vector>

using namespace std;

//和0-1背包相比，不同之处在于每种物品有无数个
//并且for循环的先后顺序是可以颠倒的
//先遍历物品再遍历背包可以解决组合问题
//先遍历背包再遍历物品可以解决排列问题

class Solution{
    int maxValue(vector<int>& weight, vector<int>& value, int bagWeight){
        int m = value.size();
        int n = bagWeight;
        vector<int> dp(n + 1, 0);

//dp数组不需要初始化，和0-1背包不同

//先遍历物品，再遍历背包的重量
        for(int i = 0; i < m; ++i){
            for(int j = weight[i]; j <= bagWeight; ++j){
//因为这里的物品可以使用无数次，所以要从头至尾遍历，与0-1背包的顺序相反
                dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
            }
        }
        return dp[n];
    }
};

class Solution{
    int maxValue(vector<int>& weight, vector<int>& value, int bagWeight){
        int m = value.size();
        int n = bagWeight;
        vector<int> dp(n + 1, 0);

//先遍历背包重量，再遍历物品
        for(int j = 0; j <= bagWeight; ++j){
            for(int i = 0; i < m; ++i){
//因为这里的物品可以使用无数次，所以要从头至尾遍历，与0-1背包的顺序相反
                if(j >= weight[i])
                    dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
            }
        }
        return dp[n];
    }
};