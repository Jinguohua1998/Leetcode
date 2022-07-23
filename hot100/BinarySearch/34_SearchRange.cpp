//思路和offer 53_01相似（完全一样）

#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1, leftIndex = -1, rightIndex = -1;
            while(left <= right){
                int mid = (left+right) >> 1;
                if(nums[mid] == target){
                    if(mid == 0 || nums[mid-1] != target){
                        leftIndex = mid;
                        break;
                    }
                    right = mid-1;   
                }else if(nums[mid] > target){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
            left = 0;
            right = nums.size()-1;
            while(left <= right){
                int mid = (left+right) >> 1;
                if(nums[mid] == target){
                    if(mid == nums.size()-1 || nums[mid+1] != target){
                        rightIndex = mid;
                        break;
                    }
                    left = mid+1;   
                }else if(nums[mid] > target){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
            return {leftIndex, rightIndex};
            
        }
};