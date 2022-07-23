#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            int m = i + (j - i)/2;
            if(nums[m] == m)
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
        //return j + 1;
    }
};