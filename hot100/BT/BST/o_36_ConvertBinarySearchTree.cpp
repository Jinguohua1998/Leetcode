
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    public:
        Node* treeToDoublyList(Node* root) {
            if(root == nullptr)
                return nullptr;
            treeToDoubleListCore(root);
            head->left = pre;
            pre->right = head;
            return head;
        }

    private:
    // head 记录已转换链表头节点
    // pre 记录已转换链表尾节点
    // 中序遍历
        Node* head = nullptr;
        Node* pre = nullptr;
        void treeToDoubleListCore(Node* cur) {
            if(cur == nullptr)
                return ; 
            treeToDoubleListCore(cur->left);
            if(pre == nullptr)
                head = cur;
            else
                pre->right = cur;
            cur->left = pre;
            pre = cur;
            treeToDoubleListCore(cur->right);
        }
};