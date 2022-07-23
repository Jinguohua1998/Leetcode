#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 二叉树的直径 ： 任意两节点的最大路径长度
// 借助求二叉树某一节点的深度来求二叉树的直径
// 该题类似于lc 124 二叉树中的最大路径和

class Solution {
    int res = 0;

    // 该函数返回节点的深度，同时在函数更新半径大小
    int depth(TreeNode* root){
        if(!root)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        res = max(left+right, res);
        // 左子树的深度left，右子树深度right，则通过该节点的最大路径长度为left+right
        return max(left, right) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {

        depth(root);
        return res;
    }
};
