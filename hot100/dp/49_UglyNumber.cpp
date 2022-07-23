#include <vector>

// 只包含 2，3，5的数叫做丑数
// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12

using namespace std;
//动态规划
class Solution{
    public:
        int nthUglyNumber(int n){
            vector<int> dp(n);
            int index1 = 0, index2 = 0, index3 = 0;
            dp[0] = 1;
            for(int i = 1; i < n; ++i){
                int n1 = dp[index1]*2, n2 = dp[index2]*3, n3 = dp[index3]*5;
                dp[i] = min(min(n1, n2), n3);
                if(dp[i] == n1)
                    ++index1;
                if(dp[i] == n2)
                    ++index2;
                if(dp[i] == n3)
                    ++index3;
            }
            return dp[n-1];
        }
};