//同offer03
//原地哈希
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
//用while而不是if
//这里的前两个判断条件与offer3不同
//判断条件应该是nums[i] <= n而不是nums[i] != i+1
                swap(nums[i], nums[nums[i]-1]);
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
//应该返回n+1
    }
};