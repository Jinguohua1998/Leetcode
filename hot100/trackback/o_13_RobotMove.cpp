//本题与12类似，是简化版
//可以分为BFS和DFS
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool check(int threhold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);
int movingCountCore(int threhold, int rows, int cols, int row, int col, bool* visited);

int movingCount(int threhold, int rows, int cols){
    if(threhold < 0 || rows <= 0 || cols <= 0)
        return 0;
    
    bool* visited = new bool[rows*cols];
    for(int i = 0; i < rows*cols; i++)
        visited[i] = false;
    
    int count = movingCountCore(threhold, rows, cols, 0, 0, visited);

    delete[] visited;

    return count;
}

int movingCountCore(int threhold, int rows, int cols, int row, int col, bool* visited){
    int count = 0;
//visited数组的标记不能放在if判断前面，因为row，col可能越界
    if(check(threhold, rows, cols, row, col, visited)){
        visited[row*cols+col] = true;
        
        count = 1 +
        movingCountCore(threhold, rows, cols, row-1, col, visited)+
        movingCountCore(threhold, rows, cols, row, col-1, visited)+
        movingCountCore(threhold, rows, cols, row+1, col, visited)+
        movingCountCore(threhold, rows, cols, row, col+1, visited); 
    }

    return count;
}

bool check(int threhold, int rows, int cols, int row, int col, bool* visited){
    if(row >= 0 && row < rows && col >= 0 && col < cols
    && getDigitSum(row) + getDigitSum(col) <= threhold
    && !visited[row*cols+col]){
        return true;
    }
    return false;
}

int getDigitSum(int number){
    int sum = 0;
    while(number != 0){
        sum += number%10;
        number /= 10;
    }
    return sum;
}

//DFS
class Solution1 {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfs(0, 0, 0, 0, visited, m, n, k);
    }
private:
    int dfs(int i, int j, int si, int sj, vector<vector<bool>> &visited, int m, int n, int k) {
        if(i >= m || j >= n || k < si + sj || visited[i][j]) return 0;
        visited[i][j] = true;
        return 1 + dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj, visited, m, n, k) +
                   dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8, visited, m, n, k);
    }
};

//BFS
class Solution2 {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        int res = 0;
        queue<vector<int>> que;
        que.push({ 0, 0, 0, 0 });
        while(que.size() > 0) {
            vector<int> x = que.front();
            que.pop();
            int i = x[0], j = x[1], si = x[2], sj = x[3];
            if(i >= m || j >= n || k < si + sj || visited[i][j]) 
                continue;

            else{
                visited[i][j] = true;
                res++;
                que.push({ i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj });
                que.push({ i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8 });
            }
        }
        return res;
    }
};


