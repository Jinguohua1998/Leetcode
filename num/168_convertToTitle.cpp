/*
给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。

例如：

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...


*/

/*
一般性的进制转换题目无须进行额外操作，是因为我们是在「每一位数值范围在 [0,x)的前提下进行「逢 xx 进一」。

但本题需要我们将从 11 开始，因此在执行「进制转换」操作前，我们需要先对 columnNumber 执行减一操作，从而实现整体偏移。


*/

#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 0) {
            columnNumber--;
            res.push_back('A' + columnNumber % 26);
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};