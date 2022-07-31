/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long a = numerator, b = denominator;
        if(a % b == 0)
            return to_string(a / b);
        string res;
        if(a * b < 0)
            res.push_back('-');
        a = abs(a);
        b = abs(b);
        res += to_string(a / b) + '.';
        a = a % b;
        unordered_map<long, int> numMap;  // key存储被除数，val记录当前余数所在答案的位置
        while( a != 0){
            numMap[a] = res.size();
            a *= 10;
            res += to_string(a / b);
            a %= b;
            if (numMap.find(a) != numMap.end()){
                int len = numMap[a];
                string cir = res.substr(len, res.size() - len);
                return res.substr(0, len) + '(' + cir + ')';
            }
        }
        return res;
    }
};