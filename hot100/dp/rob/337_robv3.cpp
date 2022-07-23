#include <unordered_map>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//树形dp
class Solution {
public:
    int rob(TreeNode* root) {
        auto res = robTree(root);
        return max(res.first, res.second);
    }

    pair<int, int> robTree(TreeNode* root){
        if(root == nullptr)
            return {0, 0};
        auto left = robTree(root->left);
        auto right = robTree(root->right);
        int selected = root->val + left.second + right.second;
        int nselected = max(left.first, left.second) + max(right.first, right.second);
        // 注意这里的nselected里面要用max
        return {selected, nselected};
    }
};

//(记忆化搜索)后序遍历
class Solution {
public:
    unordered_map<TreeNode* , int> umap; // 记录计算过的结果
    int rob(TreeNode* root) {
        if (root == NULL) 
            return 0;
        if (root->left == NULL && root->right == NULL) 
            return root->val;
//如果是叶子节点就不用放进map里面，因为递归的代价很小，放进map反而浪费内存
        if (umap[root]) 
            return umap[root]; // 如果umap里已经有记录则直接返回

        // 偷父节点
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right); // 跳过root->left
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right); // 跳过root->right
        
        // 不偷父节点
        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
        umap[root] = max(val1, val2); // umap记录一下结果
        
        return max(val1, val2);
    }
};