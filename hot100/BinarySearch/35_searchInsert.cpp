#include <vector>

using namespace std;

//寻找插入位置也就是寻找大于等于target的最小数

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target){
                right = mid -1;
            }else{
                left = mid + 1;
            }
        }
        return right + 1;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[right] >= target ? right : right + 1;
    }
};