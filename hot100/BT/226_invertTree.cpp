#include <algorithm>
#include <queue>

using namespace std;

//后序遍历的递归法，同offer 27
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//使用前序遍历和后序遍历都可以
//唯独中序遍历不方便，因为中序遍历会把某些节点的左右孩子翻转了两次
//后序
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

//前序
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) 
            return root;
        swap(root->left, root->right);  
        invertTree(root->left);         
        invertTree(root->right);        
        return root;
    }
};


//BFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right); // 节点处理
                if (node->left) 
                    que.push(node->left);
                if (node->right) 
                    que.push(node->right);
            }
        }
        return root;
    }
};