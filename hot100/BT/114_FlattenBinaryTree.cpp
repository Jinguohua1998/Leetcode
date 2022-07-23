#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归法
// 后序遍历
void FlattenBinaryTreev1(TreeNode* root){
    if(!root)
        return ;
    if(!root->left && !root->right)
        return ;
    FlattenBinaryTreev1(root->left);
    FlattenBinaryTreev1(root->right);
    TreeNode* next = root->left;
    TreeNode* predecessor = next;
    if(next == nullptr)
        return;
    while (predecessor->right != nullptr) {
        predecessor = predecessor->right;
    }
    predecessor->right = root->right;
    root->left = nullptr;
    root->right = next;
}

// 迭代
void FlattenBinaryTreev2(TreeNode* root){
    TreeNode *curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto next = curr->left;
                auto predecessor = next;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
}

int main(){
    
}