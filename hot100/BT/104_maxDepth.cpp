#include <iostream>
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
int maxDepthCore(TreeNode* root, int num);

//DFS
int maxDepthv1(TreeNode* root) {
    return maxDepthCore(root, 0);
}

int maxDepthCore(TreeNode* root, int num){
    if(root == nullptr)
        return num;
    ++num;
    return max(maxDepthCore(root->left, num), maxDepthCore(root->right, num));
}

int maxDepthv2(TreeNode* root){
    if(root == nullptr)
        return 0;
    return max(maxDepthv2(root->left), maxDepthv2(root->right)) + 1;
}

//BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++; // 记录深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
};
int main()
{
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t4;
    t1->left = t2;
    t2->right = t3;
    cout << maxDepthv1(t4);
}