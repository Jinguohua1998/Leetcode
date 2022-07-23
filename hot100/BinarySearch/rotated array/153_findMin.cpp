// 一定要将mid与r比较而不是l, 因为比较l无法判断是在哪个数组（左数组或者右数组）中

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        // 寻找极大值/极小值不用 等于号=
        while (l < r) {
            int m = l + (r - l) / 2;
            // 如果是 right = middle，则是middle = (left + right) / 2
            // 如果是 left = middle，则是middle = (left + right + 1) / 2
            if (nums[m] < nums[r]) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};