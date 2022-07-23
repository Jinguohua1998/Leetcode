#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n-1; ++i){
            int x = nums[i], y = nums[i+1];
            if(x > y){
                ++cnt;
                if(cnt > 1)
                    return false;
                if(i > 0 && nums[i-1] > y)
                // 否则就将nums[i]替换成y ： nums[i] = y,这种情况不需要写出来
                    nums[i+1] = x;
            }
        }
        return true;
    }
};