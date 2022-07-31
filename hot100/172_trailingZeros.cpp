// 给定一个整数 n ，返回 n! 结果中尾随零的数量

// 5 的个数就是 n / 5 + n / 25 + n / 125
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};