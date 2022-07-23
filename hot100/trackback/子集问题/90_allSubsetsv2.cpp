#include <vector>
#include <algorithm>

using namespace std;

// 去重的思路与lc40 组合总和类似

//用startIndex去重
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int startIndex){
        res.push_back(path);
        if(startIndex == nums.size())
            return;
//这里递归的结束条件可以不用
        for(int i = startIndex; i < nums.size(); ++i){
            if(i > startIndex && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            backtrack(nums, i+1);
//backtrack里面的参数是i+1而不是startIndex+1
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        res.clear();
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
};

//用used数组去重
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>& nums, int startIndex, vector<bool>& used) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // 去重需要排序
        backtrack(nums, 0, used);
        return result;
    }
};
