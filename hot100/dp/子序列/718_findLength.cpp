#include <string>
#include <vector>

using namespace std;

// 最长重复（公共）子数组，数组要求是连续的

// dp[i][j]:以text1[i-1]和text2[j-1]结尾的字符串最长公共子序列长度
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int res = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] += dp[i-1][j-1];
                res = max(dp[i][j], res);
            }
        }
        return res;
    }
};

//空间复杂度简化的解法
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int res = 0;
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= m; ++i){
            for(int j = n; j > 0; --j){
                if(nums1[i-1] == nums2[j-1]){
                    dp[j] = dp[j-1] + 1;
                    res = max(res, dp[j]);
                }else
                    dp[j] = 0;
            }
//注意点： 1.倒序遍历（与0-1背包类似） 2.dp[j] = 0
        }
        return res;
    }
};
