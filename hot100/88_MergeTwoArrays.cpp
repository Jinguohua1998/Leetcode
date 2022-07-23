//最优解法是逆向双指针
//类似于offer05 字符串的处理，降低空间复杂度
#include <vector>

using namespace std;

class Solution{
    public: 
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int p1 = m-1, p2 = n-1;
            int index = m + n -1;
            while( p1 >= 0 || p2 >= 0){
                if(p1 == -1)
                    nums1[index--] = nums2[p2--];
                else if(p2 == -1)
                    nums1[index--] = nums1[p1--];
                else if(nums1[p1] > nums2[p2])
                    nums1[index--] = nums1[p1--];
                else    
                    nums1[index--] = nums2[p2--];
            }
        }
};