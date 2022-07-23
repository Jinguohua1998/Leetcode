#include <vector>
#include <algorithm>

using namespace std;

//动态规划
//dp[i]表示i之前包括i的最长上升子序列的长度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > result) result = dp[i]; // 取长的子序列
        }
        return result;
    }
};

//贪心+二分查找
//核心思想：让 tails 中存储比较小的元素。
//这样，tails 未必是真实的最长上升子序列，但长度是对的

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int tails[n];
//每个元素 tails[k]的值代表 长度为 k+1 的子序列尾部元素的值
        int res = 0;
        for(auto num : nums){
            int i = 0, j = res;
//寻找比num更大的数中最小的数
            while( i < j ){
                int mid = i + (j - i)/2;
                if(tails[mid] < num)
                    i = mid+1;
                else
                    j = mid;
            }
            tails[i] = num;
            if(res == j)
                ++res;
        }
        return res;
    }
};