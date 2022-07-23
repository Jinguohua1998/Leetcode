#include <vector>

using namespace std;

// 希尔排序是插入排序的特例
void shellSort(vector<int>& nums) {
    int len = nums.size();
    //进行分组，最开始的时候，gap为数组长度一半
    for (int gap = len / 2; gap > 0; gap /= 2) {
        //对各个分组进行插入分组
        for (int i = gap; i < len; ++i) {
            //将nums[i]插入到所在分组正确的位置上
            for(int j = i; j >= gap && nums[j] < nums[j - gap]; j-= len)
                swap(nums[j], nums[j-len]);
        }
    }
}
