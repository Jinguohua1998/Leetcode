//数组中有负数值，所以不能用滑动窗口
//哈希表法,前缀和
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSum;
// key表示总和，value表示总和的个数
// 前缀和的思路类似于lc 437
        int res = 0;
        int sum = 0;
        preSum[0] = 1;
// 这一步很关键
        for(auto num : nums){
            sum += num;
            if(preSum.find(sum - k) != preSum.end()){
                res += preSum[sum - k];
            }
            ++preSum[sum];
        }
        return res;
    }
};