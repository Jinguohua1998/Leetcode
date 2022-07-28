// 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};