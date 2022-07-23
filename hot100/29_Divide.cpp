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
        while(l <= r){
            long mid = (l+r >> 1);
            if(mul(mid, y) < x){
                if(mul(mid+1, y) > x){
                    ans = mid;
                    break;
                }
                l = mid+1;     
            }else if(mul(mid, y) > x)
                r = mid - 1;
            else{
                ans = mid;
                break;
            }
        }
        long res = neg ? -ans : ans;
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