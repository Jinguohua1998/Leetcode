#include <vector>

using namespace std;

// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(int n, int k, int startIndex){
        if(path.size() == k){
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i <= n - (k - path.size()) + 1; ++i){
//i <= n - (k - path.size()) + 1是优化的地方
            path.push_back(i);
            backtrack(n, k, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        path.clear();
        res.clear();
        backtrack(n, k, 1);
        return res;
        
    }
};