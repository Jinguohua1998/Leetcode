#include <vector>

using namespace std;

// 动态规划

// dp[i][j] 表示填满开区间 (i,j) 能得到的最多硬币数
// 那么边界条件是 i≥j−1，此时有 dp[i][j]=0
// 实现时要注意到动态规划的次序
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        vector<int> val(n+2, 1);
// 在数组前后各加一个1，这样每个气球都会戳破
        for(int i = 1; i <= n; ++i)
            val[i] = nums[i-1];
        for(int i = n-1; i >= 0; --i){
// 遍历顺序是从后往前，思路和lc 647 回文子串
            for(int j = i + 2; j <= n + 1; ++j){
                for(int k = i + 1; k < j; ++k){
// k是这个区间最后一个被戳爆的气球
                    int sum = val[i] * val[k] * val[j] + dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], sum);
                }
            }
        }
        return dp[0][n+1];
    }
};


// 记忆化搜索
class Solution {
private:
    vector<int> val;
    vector<vector<int>> rec;
    int solve(int left, int right){
        if(left >= right-1)
            return 0;
        if(rec[left][right] != -1)
            return rec[left][right];
        for(int k = left+1; k < right; ++k){
            int sum = val[left]*val[right]*val[k] + solve(left, k) + solve(k, right);
            rec[left][right] = max(rec[left][right], sum);
        }
        return rec[left][right];
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n+2);
        for(int i = 1; i <= n; ++i)
            val[i] = nums[i-1];
        val[0] = val[n+1] = 1;
        rec.resize(n+2, vector<int>(n+2, -1));
        return solve(0, n+1);
    }
};