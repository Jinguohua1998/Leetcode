#include <vector>
#include <algorithm>

using namespace std;

// 给定一个无重复元素的数组 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字可以无限制重复被选取。
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
//剪枝优化：如果 sum + candidates[i] > target 就终止遍历
            path.push_back(candidates[i]);
            backtrack(candidates, target, sum+candidates[i], i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return result;
    }
};