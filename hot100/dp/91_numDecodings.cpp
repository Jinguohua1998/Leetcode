#include <string>
#include <vector>

using namespace std;

// 思路类似于 offer 46

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            if(s[i-1] != '0')
                dp[i] += dp[i-1];
            if(i >= 2 && s[i-2] != '0' && (s[i-2] - '0')* 10 + (s[i-1] - '0') < 27)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};

// 也可以用空间复杂度更小的写法