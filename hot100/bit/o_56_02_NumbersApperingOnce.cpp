#include <vector>

using namespace std;
// 其他数字都是出现了三次

//统计每一位出现1的次数（共32位），
class Solution {
    public:
        int singleNumber(vector<int>& nums){
            vector<int> counts(32, 0);
            for(auto num : nums){
                for(int i = 0; i < 32; ++i){
                    counts[i] += num & 1;
                    num >>= 1;
                }
            }
            int res = 0;
            for (int i = 0; i < 32; ++i){
                res <<= 1;
                res |= counts[31 - i] % 3;
//上面两条语句的顺序不能改变，考虑最后一位，如果颠倒次序，赋值之后又被左移，也就是*2
            }
            return res;
        }
};