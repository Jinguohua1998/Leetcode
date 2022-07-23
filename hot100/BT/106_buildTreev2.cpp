#include <vector>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return nullptr;
        return traverse(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* traverse(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd){
        if(postorderBegin > postorderEnd)
            return nullptr;
        int rootValue = postorder[postorderEnd];
        TreeNode* root = new TreeNode(rootValue);
        if(postorderBegin == postorderEnd)
            return root;
        int delimiterIndex;
        for(int i = inorderBegin; i <= inorderEnd; ++i){
            if(inorder[i] == rootValue){
                delimiterIndex = i;
                break;
            }
        }
        int leftSubtreeLen = delimiterIndex - inorderBegin ;
        root->left = traverse(inorder, inorderBegin, delimiterIndex-1, postorder, postorderBegin, postorderBegin+leftSubtreeLen-1);
        root->right = traverse(inorder, delimiterIndex+1, inorderEnd, postorder, postorderBegin+leftSubtreeLen, postorderEnd-1);
        return root;
    }
};