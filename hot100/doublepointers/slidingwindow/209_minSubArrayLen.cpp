#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int right = 0;
        int res = INT_MAX;
        for(int left = 0; left < n; ++left){
            if(left > 0)
                sum -= nums[left-1];
            while(right < n && sum < target){
                sum += nums[right++];
            }
            if(sum >= target){
                res = min(res, right-left);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

//滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT_MAX;
        int sum = 0; // 滑动窗口数值之和
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0, i = 0; j < nums.size(); j++) {
//i,j分别为滑动窗口的左右端点
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT_MAX ? 0 : result;
    }
};
