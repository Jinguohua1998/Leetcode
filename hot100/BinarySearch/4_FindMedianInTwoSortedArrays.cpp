#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        int m = nums1.size();
        int n = nums2.size();

//分割线左边的数字个数
        int totalLeft = (m + n + 1)/2;

        int left = 0, right = m;// 注意 ：是m不是m-1

//数组nums1分割线的位置：小于索引pos1的所有数
        int pos1;

        while(left <= right){
            pos1 = (right + left + 1) / 2;
// 在这里right + left 要 +1， 因为如果pos1 == 0 就要break
            int pos2 = totalLeft - pos1;
//数组nums2分割线的位置：小于索引pos2的所有数
            if(pos1 == 0)
                break;
            if(nums1[pos1-1] > nums2[pos2]){
                right = pos1-1;
            }else if(nums1[pos1-1] < nums2[pos2]){
                if(pos1 == m || nums1[pos1] > nums2[pos2-1])
                    break;
                left = pos1+1;
            }else
                break;
        }

        int pos2 = totalLeft - pos1;
        int nums1LeftMax = pos1 == 0 ? INT_MIN : nums1[pos1-1];
        int nums1RightMin = pos1 == m ? INT_MAX : nums1[pos1];
        int nums2LeftMax = pos2 == 0 ? INT_MIN : nums2[pos2-1];
        int nums2RightMin = pos2 == n ? INT_MAX : nums2[pos2];

        if(( m + n) % 2 == 1)
            return max(nums1LeftMax, nums2LeftMax);
        else{
            return (double) (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2;
        }

    }
};