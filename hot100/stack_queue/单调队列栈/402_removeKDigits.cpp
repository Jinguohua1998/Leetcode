#include <string>
#include <vector>

using namespace std;

// 去除K个数字使得剩余的数字最小的解题思路类似于让字典序最小 lc 316
// 维护一个递增栈
// 用vector代替栈
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for (auto& digit: num) {
            while (stk.size() > 0 && stk.back() > digit && k) {
//这里的>符号千万不能用>=
                stk.pop_back();
                k -= 1;
            }
            stk.push_back(digit);
        }

        for (; k > 0; --k) {
            stk.pop_back();
        }

        string res;
        bool isLeadingZero = true;
        for (auto& digit: stk) {
            if (isLeadingZero && digit == '0') {
                continue;
            }
            isLeadingZero = false;
            res.push_back(digit);
        }
        return res == "" ? "0" : res;
    }
};
