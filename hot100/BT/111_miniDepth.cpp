// 类似于lc104
// 不同的是最小深度，深度是指根节点到叶子节点的节点数，叶子节点是指该节点的左右子节点均为nullptr
// 这里不能直接用 1 + min()作为递归结果，
// 以及递归结束条件包括了两个：node == nullptr 和 node->right == nullptr && node->left == nullptr
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int minDepth(TreeNode* root) {
            if(root == nullptr) 
                return 0;

//1.左孩子和有孩子都为空的情况，说明到达了叶子节点，直接返回1即可
            if(root->left == nullptr && root->right == nullptr) 
                return 1;
//2.如果左孩子和由孩子其中一个为空，那么需要返回比较大的那个孩子的深度        
            int m1 = minDepth(root->left);
            int m2 = minDepth(root->right);
//这里其中一个节点为空，说明m1和m2有一个必然为0，所以可以返回m1 + m2 + 1;
            if(root->left == nullptr || root->right == nullptr) 
                return m1 + m2 + 1;
        
//3.最后一种情况，也就是左右孩子都不为空，返回最小深度+1即可
            return min(m1,m2) + 1; 
    }
};


//BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++; // 记录最小深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                    return depth;
                }
            }
        }
        return depth;
    }
};