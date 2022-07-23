//思路同lc54
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int num = n*n;
        for(int cir = 0, index = 1; cir <= (n+1)>>1; ++cir){
            for(int j=cir; j<n-cir && index <= num;++j,++index){
                matrix[cir][j] = index;
            }

            for(int i=cir+1; i<n-cir&& index <= num; ++i,++index){
                matrix[i][n-cir-1] = index;
            }
            
            for(int j=n-cir-2; j>=cir&& index <= num; --j,++index){
                matrix[n-cir-1][j] = index;
            }
            
            for(int i=n-cir-2; i>cir && index <= num; --i,++index){
                matrix[i][cir] = index;
            } 
        }
        return matrix;
    }
};

