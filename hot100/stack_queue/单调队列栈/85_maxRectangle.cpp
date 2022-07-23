#include <vector>
#include <stack>

using namespace std;


//动态规划
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        int dp[m][n];
//与以往的dp数组不同
//这里的dp[i][j]记录的是第i行第j列的在第i行左边为1的格点数量
//所以这里的dp数组叫left更合适一点
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == '1')
                    dp[i][j] = j == 0 ? 1 : (dp[i][j-1]+1);
                else
                    dp[i][j] = 0;
            }
        }
        int res = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(dp[i][j] == '0')
                    continue;
                int width = dp[i][j];
                int area = width;
                int k = i-1;
                while(k >= 0 && dp[k][j] != '0'){
                    width = min(dp[k][j], width);
//width的值应该是和dp[k][j]和width比较得出而不是dp[k][j]和dp[i][j]
                    area = max(area, width*(i-k+1));
                    --k;
                }
                res = max(res, area);
            }
        }
        return res;
    }
};

//得到left矩阵后（方法同上），对每一列运用单调栈的方法（同lc84）
//维护单调递增的栈
class Solution{
    public:
        int maximalRectangle(vector<vector<char>>& matrix){
            int m = matrix.size();
            if(m == 0)
                return 0;
            int n = matrix[0].size();
            int left[m][n];

            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(matrix[i][j] == '1')
                        left[i][j] = j == 0 ? 1 : left[i][j-1] + 1;
                    else    
                        left[i][j] = 0;
                }
            }
            int res = 0;
            
            // 对每一列利用单调栈
            for(int j = 0; j < n; ++j){
                vector<int> up(m,-1), down(m, m); // 记录的是在up和down方向上比该矩形低的索引
                stack<int> stk;
                for(int i = 0; i < m; ++i){
                    while(!stk.empty() && left[i][j] < left[stk.top()][j]){
//这里是left数组的元素比较而不是matrix，不能混淆
                        down[stk.top()] = i;
                        stk.pop();
                    }
                    if(!stk.empty()){
                        up[i] = stk.top();
                    }
                    stk.push(i);
                }

                for(int i = 0; i < m; ++i){
                    int area = left[i][j] * (down[i] - up[i] - 1);
                    res = max(area, res);
                }
            }
            return res;
        }
};

