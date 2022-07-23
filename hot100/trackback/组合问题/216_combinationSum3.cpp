#include <vector>

using namespace std;

// 找出所有相加之和为 n 的 k 个数的组合。
// 组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(int k, int targetSum, int sum, int startIndex){
        if(sum > targetSum)
            return;
        if(path.size() == k){
            if(sum == targetSum)
                res.push_back(path);
            return;
        }
        for(int i = startIndex; i <= 9-(k - path.size())+1; ++i){
//此处i <= 9-(k - path.size())+1是优化
            path.push_back(i);
            backtrack(k, targetSum, sum+i, i+1);
//backtrack传入的参数应该是i+1而不是startIndex+1
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear(); 
        path.clear();   
        backtrack(k, n, 0, 1);
        return res;
    }
};