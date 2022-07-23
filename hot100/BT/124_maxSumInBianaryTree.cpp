#include <algorithm>
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

// 二叉树中最大路径和，节点值有可能是负数
// 该题思路类似于 lc 543 二叉树的半径
class Solution {
    int maxSum = INT_MIN; // 二叉树的节点有可能是负值，所以要定义为INT_MIN
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }

    // 函数返回经过该节点的最大路径和，同时在内部更新整个树的最大路径和
    int maxGain(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = max(0, maxGain(root->left));
        int right = max(0, maxGain(root->right));
        maxSum = max(maxSum, left+right+root->val);
        return root->val + max(left, right);
    }
};

//运行性能更优
class Solution {
public:
    int maxPathSum(TreeNode* root, int &val){
	    if (root == nullptr) 
            return 0;
	    int left = maxPathSum(root->left, val);
	    int right = maxPathSum(root->right, val);
	    int lmr = root->val + max(0, left) + max(0, right);
	    int ret = root->val + max(0, max(left, right));
	    val = max(val, max(lmr, ret));
	    return ret;
    }

    int maxPathSum(TreeNode* root) {
	    int val = INT_MIN;
	    maxPathSum(root, val);
	    return val;
    }
};