#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)
            return {0};
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
        // 如果是奇数，则等于上一个偶数+1，如果是偶数，则等于该数/2的数左移一位
            if(i%2)
                dp[i] = dp[i-1]+1;
            else
                dp[i] = dp[i/2];
        }
        return dp;
    }
};