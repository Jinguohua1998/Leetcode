#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSubStructure(TreeNode* t1, TreeNode* t2) {
        if(t2 == nullptr || t1 == nullptr)
            return false;
        if(hasSubTree(t1, t2))
            return true;
        else
            return isSubStructure(t1->left, t2) || isSubStructure(t1->right, t2);
    }
    bool hasSubTree(TreeNode* t1, TreeNode* t2){
        if(t2 == nullptr)
            return true;
        if(t1 == nullptr)
            return false;
        if(t1->val == t2 ->val){
            return hasSubTree(t1->left, t2->left) && hasSubTree(t1->right, t2->right);
        }else{
            return false;
        }
    }
};
