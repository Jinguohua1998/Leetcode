#include <string>
#include <algorithm>

using namespace std;

// 类似的题 lc 415 十进制的加法
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        // reverse的方法类似于lc 43
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        // 也可以不用reverse的方法，对两个字符串定义双指针

        int n = max(a.size(), b.size());
        int carry = 0;
        for(int i = 0; i < n; ++i){
            carry += i < a.size() ? (a[i] == '1') : 0;
            carry += i < b.size() ? (b[i] == '1') : 0;
            res.push_back((carry%2) ? '1' : '0');
            carry /= 2;
        }
        if(carry)
            res.push_back('1');
        reverse(res.begin(), res.end());

        return res;
    }
};