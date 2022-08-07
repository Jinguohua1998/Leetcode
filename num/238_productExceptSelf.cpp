// 除自身以外数组的乘积
//构造乘积数组，同 offer66
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

//先计算下三角
        for(int i = 1; i < n; ++i){
            res[i] = nums[i-1]*res[i-1];
        }

//再计算上三角
        int tmp = 1;
        for(int i = n - 1; i >= 0; --i){
            res[i] *= tmp;
            tmp *= nums[i];
        }
        return res;
    }
};