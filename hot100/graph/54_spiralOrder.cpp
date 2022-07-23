// 同offer 29 
// 思路同 lc 59
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return {};
        int n = matrix[0].size();
        vector<int> res(m*n);
        int index = 0;
        for(int cir = 0; cir < (m+1)/2; ++cir){
        // 遍历过程中维护两个变量，index和cir
            for(int j = cir; j < n-cir && index < m*n; ++j, ++index)
                res[index] = matrix[cir][j];
            for(int i = cir+1; i < m-cir && index <m*n; ++i, ++index)
                res[index] = matrix[i][n-cir-1];
            for(int j = n-cir-2; j >= cir && index < m*n; --j, ++index)
                res[index] = matrix[m-cir-1][j];
            for(int i = m-cir-2; i > cir && index < m*n; --i, ++index)
                res[index] = matrix[i][cir];
        }
        return res;
    }
};