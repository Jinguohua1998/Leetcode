#include <queue>
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


// 要找到最下面一层最左边的节点

//迭代法比较简单
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        int res; 
        while(!nodeQ.empty()){
            int n = nodeQ.size();
            res = nodeQ.front()->val;
            for(int i = 0; i < n; ++i){
                auto node = nodeQ.front();
                nodeQ.pop();
                if(node->left)
                    nodeQ.push(node->left);
                if(node->right)
                    nodeQ.push(node->right);
            }
        }
        return res;
    }
};


//回溯法
class Solution {
public:
    int maxLen = INT_MIN;
    int maxleftValue;
    void traversal(TreeNode* root, int leftLen) {
        if (root->left == NULL && root->right == NULL) {
            if (leftLen > maxLen) {
                maxLen = leftLen;
                maxleftValue = root->val;
            }
            return;
        }
        if (root->left) {
            traversal(root->left, leftLen + 1);  // leftLen + 1操作隐藏了回溯的剪枝操作
        }
        if (root->right) {
            traversal(root->right, leftLen + 1); // // leftLen + 1操作隐藏了回溯的剪枝操作
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return maxleftValue;
    }
};