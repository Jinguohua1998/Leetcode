/*
给定两个整数，被除数 dividend 和除数 divisor。
将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，
例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

*/

// 快速乘的思路和lc50快速幂的思路相同
#include <climits>

using namespace std;

class Solution {

public:
    int divide(int dividend, int divisor) {
        // 用long数据类型是因为INT_MIN转成正数有可能会溢出
        long x = dividend, y = divisor;
        bool neg = false;
        if((x > 0 && y < 0) || (x < 0 && y > 0))
            neg = true;
        if(x < 0)
            x = -x;
        if(y < 0)
            y = -y;
        long l = 0, r = x, ans;
        // 二分法
        while(l <= r){
            long mid = l + (r - l) / 2;
            if(mul(mid, y) < x){
                l = mid + 1;     
            }else if(mul(mid, y) > x)
                r = mid - 1;
            else{
                r = mid;
                break;
            }
        }
        long res = neg ? -r : r;
        if(res > INT_MAX || res < INT_MIN)
            return INT_MAX;
        return (int)res;
    }

private:
// 快速乘，用移位运算和加法代替乘法
    long mul(long x, long y){
// x和y是正数
        long res = 0;
        while(y > 0){
            if((y & 1) == 1)
                res += x;
            y >>= 1;
            x += x;
        }
        return res;      
    }
};