#include <vector>

using namespace std;

//双指针法（快慢指针法）

int partition(vector<int>& nums, int l, int r) {
    int pivot = nums[l];
    int i = l;
    for (int j = l+1; j <= r; ++j) {
        if (nums[j] <= pivot) {
            i = i + 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i], nums[l]);
    return i;
}

void QuickSort(vector<int>& nums, int l, int r){
    if( l >= r)
        return;
    int m = partition(nums, l, r);
    QuickSort(nums, l, m-1);
    QuickSort(nums, m+1, r);
}

void QuickSort(vector<int>& nums){
    QuickSort(nums, 0, nums.size()-1);
}
