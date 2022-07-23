// 荷兰国旗问题,O(n)的时间复杂度
// 排序0 1 2三个数字
#include <vector>
#include <algorithm>
using namespace std;

//双指针法
//left标记0与1的边界，right标记2与1的边界
class Solution {
    public:
        void sortColors(vector<int>& nums){
            int n = nums.size();
            int left = 0, right = n-1;
            for (int i = 0; i <= right; ++i){
                while(i <= right && nums[i] == 2){
                    swap(nums[i], nums[right]);
                    --right;
                }
                if(nums[i] == 0 ){
                    swap(nums[i], nums[left]);
                    ++left;
                }
            }
        }
};

//单指针法
class Solution{
    public:
        void sortColors(vector<int>& nums){
            int n = nums.size();
            int ptr = 0;
            for(int i = 0; i < n; ++i){
                if(nums[i] == 0 ){
//这里不能判断不能在后面加 && i != ptr，因为不管怎样都要++ptr
                    swap(nums[i], nums[ptr]);
                    ++ptr;
                }    
            }
            for(int i = ptr; i < n; ++i){
                if(nums[i] == 1 ){
                    swap(nums[i], nums[ptr]);
                    ++ptr;
                }
            }
        }
};

//双指针法
//p0标记0，p1标记1
class Solution2 {
    public:
        void sortColors(vector<int>& nums){
            int n = nums.size();
            int p0 = 0, p1 = 0;
            for (int i = 0; i < n; ++i){
                if(nums[i] == 1){
                    swap(nums[i], nums[p1]);
                    ++p1;
                }
                if(nums[i] == 0){
                    swap(nums[i], nums[p0]);
                    if(p0 < p1){
                        swap(nums[i], nums[p1]);
                    }
                    ++p0;
                    ++p1;
                }
            }
        }
};

