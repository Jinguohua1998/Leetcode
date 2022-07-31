#include <vector>
#include <algorithm>

using namespace std;

// 下一个字典序更大的排列
// 见题解
// https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/

class Solution{
public:
    void nextPermutation(vector<int>& nums) {
        int i;
//第一步：寻找非降序的a[i]
        for(i = nums.size()-2; i >= 0; --i) {
            if(nums[i] < nums[i+1])
                break;
        }
//第二步：寻找右边最小的“较大数”
        if(i >= 0) {
            int j = nums.size() - 1;
            while(j >= 0 && nums[i] >= nums[j]){
                --j;
            }
            swap(nums[i], nums[j]);
        }
//第三步：反转a[i]之后的元素
    reverse(nums.begin() +i +1, nums.end());
    }
};