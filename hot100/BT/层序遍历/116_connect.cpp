#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 层序遍历
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                que.pop();
                if (i != size - 1) {
                    node->next = que.front();   // 如果不是最后一个Node 则指向下一个Node
                } else node->next = nullptr;    // 如果是最后一个Node 则指向nullptr
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
        }
        return root;
    }
};

// 前序遍历
class Solution {
private:
    void traversal(Node* cur) {
        if (cur == NULL) return;
                                // 中
        if (cur->left) cur->left->next = cur->right; // 操作1
        if (cur->right) {
            if (cur->next) cur->right->next = cur->next->left; // 操作2
            else cur->right->next = NULL;
        }
        traversal(cur->left);   // 左
        traversal(cur->right);  // 右
    }
public:
    Node* connect(Node* root) {
        traversal(root);
        return root;
    }
};