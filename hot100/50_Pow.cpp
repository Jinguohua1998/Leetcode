// 快速幂
// 原理和lc29 快速乘类似，快速乘的res初始值为0.0，快速幂的res初始值为1.0
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0)
            return 0.0;
        long b = n;
        // 这里用long类型取代int是因为INT_MIN转换成正数可能会溢出
        if(b < 0){
            x = 1/x;
            b = -b;
        }
        double res = 1.0;
        while(b > 0){
            if((b&1) == 1)
                res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
            
    }
};