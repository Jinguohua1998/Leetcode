#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// 三角形的最大路径和

//动态规划
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            // 每一行最右边的数
            f[i] = f[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) { // 这里要倒序遍历
                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
            }
            // 每一行最左边的数
            f[0] += triangle[i][0];
        }
        return *min_element(f.begin(), f.end());
    }
};


//回溯法超出时间限制
class Solution {
private:
    int sum = 0;
    int res = INT_MAX;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        backtrack(triangle, 0, 0);
        return res;
    }

    void backtrack(vector<vector<int>>& triangle, int row, int index){
        if(row == triangle.size()){
            res = min(res, sum);   
            return; 
        }
        sum += triangle[row][index];
        backtrack(triangle, row+1, index);
        backtrack(triangle, row+1, index+1);
        sum -= triangle[row][index];
    }
};