#include <string>

using namespace std;

// 同 offer 44

class Solution{
    public:
        int findNthDigit(int n){
            int digit = 1;
//digit：第n位
            long start = 1;
//start：第n位开始的第一位数
            long count = 9;
//count: n位数字的个数
            while (n > count){
                n -= count;
                digit += 1;
                start *= 10;
                count = digit * start * 9;
            }
            long num = start + (n - 1)/digit;
            return to_string(num).at((n - 1) % digit) - '0';
//注意要减去‘0’
//string.at 等价于 string[]
    }
};