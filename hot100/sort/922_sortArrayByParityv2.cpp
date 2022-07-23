#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int oddIndex = 1;
        for (int i = 0; i < A.size(); i += 2) {
            if (A[i] % 2 == 1) { // 在偶数位遇到了奇数
                while(A[oddIndex] % 2 != 0) 
                    oddIndex += 2; // 在奇数位找一个偶数
                swap(A[i], A[oddIndex]); // 替换
            }
        }
        return A;
    }
};