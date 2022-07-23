struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 注意 ： 这里的左叶子节点而不是左节点
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int sum = 0;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            sum  = root->left->val;
        sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return sum; 
    }
};