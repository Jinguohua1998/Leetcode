#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 同offer 34

// 返回所有路径
// 回溯
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(TreeNode* cur, int count) {
        path.push_back(cur->val);
        if (!cur->left && !cur->right && count == cur->val) { 
            result.push_back(path);
        }
        if (cur->left) { 
            backtrack(cur->left, count - cur->val);    
        }
        if (cur->right) { 
            backtrack(cur->right, count - cur->val);  
        }
        path.pop_back();
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
        path.clear();
        if (root == nullptr) 
            return result;
        backtrack(root, sum);
        return result;
    }
};
