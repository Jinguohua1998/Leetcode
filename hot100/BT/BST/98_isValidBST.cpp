//要重点注意：二叉搜索树的性质不仅仅是邻近父节点与子节点的大小关系

#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归调用（中序遍历）

class Solution {
private:
    TreeNode* pre = nullptr;  // 保留前序节点
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        bool left = isValidBST(root->left);
        if(!left)
            return false;
        if(pre != nullptr && root->val <= pre->val)
            return false;
        pre = root;
        bool right = isValidBST(root->right);
        return right;
    }
};

