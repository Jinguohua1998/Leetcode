// 给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10^n 。
#include <bits/stdc++.h>

using namespace std;

// 阶乘
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 10;
        int res = 10, cur = 9;
        for(int i = 0; i < n - 1; ++i){
            cur *= 9 - i;
            res += cur;
        }
        return res;
    }
};