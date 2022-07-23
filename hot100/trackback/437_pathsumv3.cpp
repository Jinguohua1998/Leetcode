#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 路径可以不从根节点开始
// 前缀法+回溯
// 前缀和的思路类似于lc 560

class Solution{
    unordered_map<long long, int> prefix;  // 前缀和，指的是root节点到某一节点的和
    int backtrack(TreeNode* root, long long curr, int targetSum){
        if(root == nullptr)
            return 0;
    
        int ret = 0;
        curr += root->val;
        if(prefix.count(curr - targetSum) != 0)
            ret = prefix[curr - targetSum];

        ++prefix[curr];
        ret += backtrack(root->left, curr, targetSum);
        ret += backtrack(root->right, curr, targetSum);
        --prefix[curr];

        return ret;
    }
    int pathSum(TreeNode* root, int targetSum){
        prefix[0] = 1;
        return backtrack(root, 0, targetSum);
    }
};


//DFS
class Solution {
public:
    int dfs(TreeNode* root, int targetSum){
        if(root == nullptr)
            return 0;
        int res = 0;
        if(root->val == targetSum)
            res = 1;
        res += dfs(root->left, targetSum-root->val) + dfs(root->right, targetSum-root->val);
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return 0;
        // 前序遍历
        int res = dfs(root, targetSum);
        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);
        return res;
    }
};


