struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 将节点分为三种状态
 // 0 监控
 // 1 覆盖
 // 2 无覆盖
// 贪心算法 ： 摄像头不放在叶子节点，放在叶子节点的父节点

class Solution {
private:
    int res;
    int traverse(TreeNode* root){
        if(root == nullptr)
            return 1;
        int left = traverse(root->left);
        int right = traverse(root->right);
        // 条件判断的顺序不能改变，要把 left == 2 || right == 2放在最前面，如果有没有覆盖的子节点，父节点一定要变成监控节点
        if(left == 2 || right == 2){
            ++res;
            return 0;
        }else if(left == 0 || right == 0){
            return 1;
        }else{
            return 2;
        }
    }

public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        // 注意 ：要考虑根节点有没有覆盖
        if(traverse(root) == 2)
            ++res;
        return res;
    }
};