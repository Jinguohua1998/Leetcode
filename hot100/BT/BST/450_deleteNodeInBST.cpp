//删除操作与插入操作的思路相对应，如lc701
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//可以延伸到删除二叉树的某个节点
//分为两种情况
//1.被删除节点有两个子节点
//2.被删除节点仅有一个子节点或没有子节点

//递归法
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        if(root->val > key)
            root->left =  deleteNode(root->left, key);
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else{
            if(root->left == nullptr){
                auto res = root->right;
                delete root;
                return res;
            }else if(root->right == nullptr){
                auto res = root->left;
                delete root;
                return res;
            }else{
// 下面是关键步骤
// 找到右子树上的最左节点， 将要删除节点的左子树放到该节点的左子树, root = root->right
                auto cur = root->right;
                while(cur->left != nullptr){
                    cur = cur->left;
                }
                cur->left = root->left;
                auto tmp = root;
                root = root->right;
                delete tmp;
            }
        }
        return root;     
    }
};

