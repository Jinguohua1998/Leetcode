//该问题可以转化为lc 416
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int stones : stones)
            sum += stones;
        int target = sum/2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for(int i = 0; i < n; ++i){
            for(int j = target; j >= stones[i]; --j){
                dp[j] = dp[j] || dp[j-stones[i]];
            }
        }
        int res;
        for(int i = target; i >= 0; --i){
            if(dp[i]){
                res = i;
                break;
            }
        }
        return sum-res-res;
    }
};