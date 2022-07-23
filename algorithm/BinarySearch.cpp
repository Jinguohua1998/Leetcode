#include <iostream>
#include <stdexcept>
#include <vector>
//#include <exception>
using namespace std;


bool BinarySearch(vector<int>& nums, int target){
    int i = 0, j = nums.size() - 1;
    while( i <= j){
//判断条件是i <= j
        int m = i + ((j - i) >> 1);
//移位运算一定要加括号
        if(nums[m] == target)
            return true;
        if(nums[m] > target)
            j = m - 1;
        else    
            i = m + 1;
    }
    return false;
}


//用二分查找法计算一个数的平方根


//查找第一个值等于给定值的元素
int binarySearchv1(vector<int>& nums, int value){
    int r = nums.size()-1;
    int l = 0;
    while(l <= r){
        int mid = l + ((r-l) >> 1);
        if(nums[mid] < value)
            l = mid+1;
        else if(nums[mid] > value)
            r = mid-l;
        else{
            if(mid == 0 || nums[mid-1] != value)
                return mid;
            else
                r = mid -1 ;
        }
    }
    return -1;
}

//查找最后一个值等于给定值的元素
int binarySearchv2(vector<int>& nums, int value){
    int r = nums.size()-1;
    int l = 0;
    while(l <= r){
        int mid = l + ((r-l) >> 1);
        if(nums[mid] < value)
            l = mid+1;
        else if(nums[mid] > value)
            r = mid-l;
        else{
            if(mid == nums.size()-1 || nums[mid+1] != value)
                return mid;
            else
                l = mid + 1 ;
        }
    }
    return -1;
}

//查找第一个大于等于给定值的元素
int binarySearchv3(vector<int>& nums, int value){
    int r = nums.size()-1;
    int l = 0;
    while(l <= r){
        int mid = l + ((r-l) >> 1);
        if(nums[mid] >= value){
            if(mid == 0 || nums[mid-1] < value)
                return mid;
            else
                r = mid-1;
        }else
            l = mid+1;  
    }
    return -1;
}

//查找最后一个小于等于给定值的元素
int binarySearchv4(vector<int>& nums, int value){
    int r = nums.size()-1;
    int l = 0;
    while(l <= r){
        int mid = l + ((r-l) >> 1);
//位运算一定要加括号
        if(nums[mid] <= value){
            if(mid == nums.size()-1 || nums[mid+1] > value)
                return mid;
            else
                l = mid+1;  
        }else
            r = mid-1;   
    }
    return -1;
}

int main()
{
    
}