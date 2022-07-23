#include <stack>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) {
            deque<int> levelList;
            int size = nodeQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (isOrderLeft) {
                    levelList.push_back(node->val);
                } else {
                    levelList.push_front(node->val);
                }
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
        }

        return ans;
    }
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> valvec;
    if(!root){
        return valvec;
    }
    vector<stack<TreeNode*>> nodeVec(2);
    //可以用两个栈也可以用一个deque
    int current = 0;
    nodeVec[0].push(root);
    while(!nodeVec[0].empty() || !nodeVec[1].empty()){
        vector<int> intVec;
        while(!nodeVec[current].empty()){
            TreeNode* node = nodeVec[current].top();
            nodeVec[current].pop();
            intVec.push_back(node->val);
            if(current == 0){
                if(node->left)
                    nodeVec[1-current].push(node->left);
                if(node->right)
                    nodeVec[1-current].push(node->right);
            }else{
                if(node->right)
                    nodeVec[1-current].push(node->right);
                if(node->left)
                    nodeVec[1-current].push(node->left);
            }
        }
        valvec.push_back(intVec);
        current = 1 - current;
    }
    return valvec;
}

