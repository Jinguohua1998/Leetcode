#include <string>

using namespace std;
//局部最优：遇到strNum[i - 1] > strNum[i]的情况，让strNum[i - 1]--，然后strNum[i]给为9，可以保证这两位变成最大单调递增整数
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
// flag用来标记赋值9从哪里开始
// 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int len = strNum.size();
        int flag = strNum.size();
        for(int i = len-1; i > 0; --i){
            if(strNum[i-1] > strNum[i]){
                --strNum[i-1];
                flag = i;
            }
        }
        for(int i = flag; i < len; ++i){
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};