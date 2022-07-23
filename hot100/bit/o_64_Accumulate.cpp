#include <vector>

using namespace std;

class Solution {
    public:
        int sumNums(int n){
            n && (n += sumNums(n-1));
            // 逻辑运算符的短路效应，如果n == 0，则不用执行后半句
            return n;
        }
};