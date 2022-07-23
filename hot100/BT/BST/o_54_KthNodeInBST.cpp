
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//利用中序遍历的思想
class Solution {
    public:
        int kthLargest(TreeNode* root, int k) {
            this->k = k;
            kthLargestCore(root);
            return res;
        }

        void kthLargestCore(TreeNode* root){
            if(root == nullptr)
                return;
            kthLargestCore(root->right);
//是寻找第k大的数，所以是倒序的中序遍历，先遍历右子树，后遍历左子树
            if(k == 1)
                res = root->val;
            else if(k < 1)
                return;
            --k;
            kthLargestCore(root->left);
        }
//递归调用中需要一直使用的数，既可以用指针/引用作为参数传入，也可以作为类中的private成员
    private:
        int k, res;
};