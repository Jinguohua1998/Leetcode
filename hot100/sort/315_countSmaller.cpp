#include <bits/stdc++.h>

using namespace std;

// 计算右侧小于当前元素的个数
// 归并排序时，将tmp数组设置为merge函数的外部变量更省时

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int index[n];
        int tmp[n];
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i){
            index[i] = i;
            res[i] = 0;
        }
        mergeSort(nums, 0, n-1, index, tmp, res);
        return res;
    }

    void mergeSort(vector<int>& nums, int left, int right, int* index, int* tmp, vector<int>& res){
        if(left == right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, index, tmp, res);
        mergeSort(nums, mid + 1, right, index, tmp, res);
        // 归并排序的优化
        if(nums[index[mid]] <= nums[index[mid + 1]])
            return;
        merge(nums, left, mid, right, index, tmp, res);
    }

    void merge(vector<int>& nums, int left, int mid, int right, int* index, int* tmp, vector<int>& res){
        // int tmp[nums.size()];
        for(int i = left; i <= right; ++i){
            tmp[i] = index[i];
        }
        int i = left;
        int j = mid + 1;
        for(int k = left; k <= right; ++k){
            if(i > mid){
                index[k] = tmp[j];
                ++j;
            }else if(j > right){
                index[k] = tmp[i];
                ++i;
                res[index[k]] += right - mid;
            // 注意这里是 <= ，保证稳定性
            }else if(nums[tmp[i]] <= nums[tmp[j]]){
                index[k] = tmp[i];
                ++i;
                res[index[k]] += (j - mid - 1);
            }else{
                index[k] = tmp[j];
                ++j;
            }
        }
    }
};