//同offer68.2
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//递归（后序遍历）:其实回溯的思想
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//递归的结束条件
        if(root == nullptr || root == p || root == q){
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr)
            return root;

        if(left == nullptr)
            return right;
        else
            return left;
    }
};