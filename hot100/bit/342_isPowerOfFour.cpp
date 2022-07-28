// 判断一个数是不是4的幂次方
// 如果一个数n是4的幂次方，n=4^a=2^(2*a)
// 所以在二进制表示中，只有一位是1，且该位是偶数位

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};