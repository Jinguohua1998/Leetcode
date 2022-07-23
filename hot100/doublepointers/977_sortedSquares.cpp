#include <vector>

using namespace std;

// 指定左右两端指针left和right
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int left = 0, right = n-1, pos = n-1; left <= right;){
            if(nums[left]*nums[left] > nums[right]*nums[right]){
                res[pos] = nums[left]*nums[left];
                ++left; 
            }else{
                res[pos] = nums[right]*nums[right];
                --right;
            }
            --pos;
        }
        return res;
    }
};