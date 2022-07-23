#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n ; ++i){
            index[inorder[i]] = i;
        }
        return buildTreeCore(preorder, inorder, 0, n-1, 0, n-1);
    }

private:
    unordered_map<int, int> index;
    TreeNode* buildTreeCore(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right){
        if(pre_left > pre_right)
            return nullptr;
        
        int pre_root = pre_left;
        int in_root = index[preorder[pre_root]];

        TreeNode* root = new TreeNode(preorder[pre_root]);

        int leftSubtreeSize = in_root - in_left;
        root->left = buildTreeCore(preorder, inorder, pre_left+1, pre_left+leftSubtreeSize, in_left, in_root-1);
        root->right = buildTreeCore(preorder, inorder, pre_left+leftSubtreeSize+1, pre_right, in_root+1, in_right);
        return root;
    }
};