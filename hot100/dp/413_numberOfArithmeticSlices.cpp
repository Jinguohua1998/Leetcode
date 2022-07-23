#include <vector>

using namespace std;

// 本题是需要求等差数列的个数，该等差数列在数组中必须是连续的（关键条件）

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        vector<int> dp(n, 0);
        int res = 0;
        for(int i = 2; i < n; ++i){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = dp[i-1]+1;
                res += dp[i];
            }
        }
        return res;
    }
};