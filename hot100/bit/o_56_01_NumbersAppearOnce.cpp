#include <vector>

using namespace std;

class Solution{
    public:
        vector<int> singleNumbers(vector<int>& nums){
            int x = 0, y = 0;
            int n = 0, m = 1;
            for(auto num : nums)
                n ^= num;
// n的结果是 x ^ y， x y为两个出现一次的数字
            while(!(m & n))
// m左移要用m <<= 1而不是 m << 1
// 这一步的目的是找到n的哪一位是1
// 进一步确定x y哪一位不同，然后跟这一位分成两组
                m <<= 1;
            for(auto num : nums){
                if(num & m)
                    x ^= num;
                else
                    y ^= num;
            }
            return {x, y};
        }
};