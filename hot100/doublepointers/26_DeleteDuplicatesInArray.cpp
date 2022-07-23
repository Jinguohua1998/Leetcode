#include <vector>

using namespace std;

//快慢指针法
class Solution{
    public:
        int removeDuplicates(vector<int>& nums){
            int n = nums.size();
            if(n == 0)
                return 0;
            int slow = 0;
            for(int fast = 1; fast < n; ++fast){
                if(nums[fast] != nums[slow]){
                    if(fast - slow > 1)
                        nums[++slow] = nums[fast];
                    else
                        ++slow;
                }
            }
            return slow + 1;
        }
};


