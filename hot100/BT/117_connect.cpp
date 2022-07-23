#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 填充每个节点的下一个右侧节点指针v2

// O(1)空间复杂度
// 保存前序节点pre
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        Node* cur = root;
        while(cur != nullptr)
        {
            Node* dummy = new Node(0);
            Node* pre = dummy;
            while(cur != nullptr){
                if(cur->left){
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if(cur->right){
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;
        }
        return root;
    }
};

// 层序遍历
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        queue<Node*> nodeQ;
        nodeQ.push(root);
        while(!nodeQ.empty()){
            int levelCnt = nodeQ.size();
            Node* pre = nullptr;
            for(int i = 0; i < levelCnt; ++i){
                Node* node = nodeQ.front();
                nodeQ.pop();
                if(pre == nullptr){
                    pre = node;
                }else{
                    pre->next = node;
                    pre = pre->next;
                }
                if(node->left != nullptr)
                    nodeQ.push(node->left);
                if(node->right != nullptr)
                    nodeQ.push(node->right);
            }
        }
        return root;
    }
};