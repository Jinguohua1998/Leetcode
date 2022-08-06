#include <vector>

using namespace std;

// 归并排序
// 归并排序需要O(n)的空间复杂度，所以需要多一个vector
class Solution1 {
    public:
        int reversePairs(vector<int>& nums){
            vector<int> tmp(nums.size());
            return mergeSort(0, nums.size()-1, nums, tmp);
        }

        int mergeSort(int left, int right, vector<int>& nums, vector<int>& tmp){
//终止条件
            if(left >= right)
                return 0;
//递归划分
            int middle = left + (right-left)/2;
            int res = mergeSort(left, middle, nums, tmp) + mergeSort(middle+1, right, nums, tmp);
//合并阶段
            int i = left, j = middle+1;
            for(int k = left; k <= right; ++k)
                tmp[k] = nums[k];
            for(int k = left; k <= right; ++k){
                if( i == middle+1)
                    nums[k] = tmp[j++];
                else if( j == right+1)
                    nums[k] = tmp[i++];
                else if(tmp[i] <= tmp[j])
                    nums[k] = tmp[i++];
                else{
                    nums[k] = tmp[j++];
                    res += middle - i + 1;
                }
            }
            return res;
        }
};