#include <queue>
#include <utility>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 回溯法
class Solution {
private:
    bool backtrack(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == cur->val) 
            return true; 
        if (!cur->left && !cur->right) 
            return false; 

        if (cur->left) { 
            if (backtrack(cur->left, count - cur->val)) 
                return true;
        }
        if (cur->right) { 
            if (backtrack(cur->right, count - cur->val)) 
                return true;
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) 
            return false;
        return backtrack(root, sum);
    }
};


//BFS
//BFS 使用 队列 保存遍历到每个节点时的路径和
class solution {

public:
    bool haspathsum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        // 此时栈里要放的是pair<节点指针，路径数值>
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int>(root, root->val));
        while (!st.empty()) {
            pair<TreeNode*, int> node = st.top();
            st.pop();
            // 如果该节点是叶子节点了，同时该节点的路径数值等于sum，那么就返回true
            if (!node.first->left && !node.first->right && sum == node.second) return true;

            // 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
            if (node.first->right) {
                st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
            }

            // 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
            if (node.first->left) {
                st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
            }
        }
        return false;
    }
};
