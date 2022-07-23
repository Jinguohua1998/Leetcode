#include <vector>

using namespace std;

// 这一题与lc 240不同，一个是可以看出连续的一维数组，一个只能看出二维的二分查找

//一次二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            int x = matrix[mid / n][mid % n];
            if (x < target) {
                low = mid + 1;
            } else if (x > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};


//两次二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m-1;
        int row;
        while(left <= right){
            int mid = left + (right - left) >> 1;
//移位运算一定要加括号
            if(matrix[mid][n-1] > target){
                if(mid == 0 || matrix[mid-1][n-1] < target){
                    row = mid;
                    break;
                }else
                    right = mid-1;
            }else if(matrix[mid][n-1] < target){
                if(mid == m-1)
                    return false;
                else
                    left = mid+1;
            }else   
                return true;
        }
        left = 0;
        right = n-1;
        while(left <= right){
            int mid = left + (right- left) >> 1;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] > target)
                right = mid-1;
            else    
                left = mid+1;
        }
        return false;
    }
};



//等效成BST
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        // 右上角开始查找
        for(int i = 0, j = col-1; i < row && j >= 0;) {
            if(matrix[i][j] == target) 
                return true;
            else if(matrix[i][j] > target) 
                j--;
            else if(matrix[i][j] < target)
                i++;
        }
        return false;
    }
};
