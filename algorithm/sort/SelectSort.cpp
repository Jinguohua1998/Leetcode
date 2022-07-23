#include <vector>

using namespace std;

void selectSort(vector<int>& nums) {
    int len = nums.size();
    int minIndex = 0;
    for (int i = 0; i < len; ++i) {
        minIndex = i;
        for (int j = i + 1; j < len; ++j) {
            if (nums[j] < nums[minIndex]) minIndex = j;
        }
        swap(nums[i], nums[minIndex]);
    }
}
