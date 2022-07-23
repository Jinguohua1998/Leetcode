// 去重问题需要用used数组，去重问题思路和lc47类似
// 需要考虑去重的问题 ：旋转数组中的查找，双指针问题，回溯法（组合问题，子集问题，排列问题）
#include <vector>
#include <algorithm>

using namespace std;
// 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用一次。

// 集合（数组candidates）有重复元素，但还不能有重复的组合。
// 解决思路 ： 利用used数组进行去重
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(candidates[i]);
            used[i] = true;
            backtrack(candidates, target, sum+candidates[i], i + 1, used); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        // 去重问题都需要排序
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, used);
        return result;
    }
};

//使用startIndex进行去重
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
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, sum, i + 1); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return result;
    }
};