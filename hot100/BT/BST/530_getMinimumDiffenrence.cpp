#include <climits>
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

//遍历方法类似于lc 98，也就是保留前节点pre
class Solution {
private:
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* cur){
        if(cur == nullptr)
            return;
        traversal(cur->left);
        if(pre != nullptr){
            res = min(res, cur->val - pre->val);
        }
        pre = cur;
        traversal(cur->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};