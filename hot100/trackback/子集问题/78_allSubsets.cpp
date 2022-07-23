#include <vector>

using namespace std;

//回溯法
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int>& nums, int startIndex) {
        res.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉自己
        if (startIndex == nums.size()) { // 终止条件可以不加
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtrack(nums, 0);
        return res;
    }
};


//迭代法+位运算
//如果nums有n个元素，则有2^n种可能
//注意1 << n的意义是1左移n位，即2^n， 如1 << 0 = 1
class Solution {
    vector<int> t;
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for(int mask = 0; mask < (1 << n); ++mask){
            t.clear();
            for(int i = 0; i < n; ++i){
                if(mask & (1 << i)){
                    t.push_back(nums[i]);
                }
            }
            res.push_back(t);
        }
        return res;
    }
};

