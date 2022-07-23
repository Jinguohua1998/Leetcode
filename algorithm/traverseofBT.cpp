#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//迭代遍历
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//前序遍历

class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> res;
        if(root == nullptr)
            return res;
        st.push(root);
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }
        return res;
    }

};

// 统一迭代法
// 要处理的节点放入栈中之后，紧接着放入一个空指针作为标记
// 要访问的节点后面不加空指针
// 前序遍历
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        if(root == nullptr)
            return {};
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            if(node != nullptr){
                if(node->right != nullptr){
                    stk.push(node->right);
                }
                if(node->left != nullptr){
                    stk.push(node->left);
                }    
                stk.push(node);
                stk.push(nullptr);  
            }else{
                node = stk.top();
                stk.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};

//中序遍历
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};

//统一迭代法
//要处理的节点放入栈中之后，紧接着放入一个空指针作为标记
//要访问的节点后面不加空指针
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        if(root == nullptr)
            return {};
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            if(node != nullptr){
                if(node->right != nullptr){
                    stk.push(node->right);
                }
                stk.push(node);
                stk.push(nullptr);
                if(node->left != nullptr){
                    stk.push(node->left);
                }      
            }else{
                node = stk.top();
                stk.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};

//后序遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) 
            return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) 
                st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right) 
                st.push(node->right); // 空节点不入栈
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};


//统一迭代法
//要处理的节点放入栈中之后，紧接着放入一个空指针作为标记
//要访问的节点后面不加空指针
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node != NULL) {
                st.push(node);                          // 中
                st.push(NULL);
                if (node->right) 
                    st.push(node->right);  // 右
                if (node->left) 
                    st.push(node->left);    // 左

            } else {
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};