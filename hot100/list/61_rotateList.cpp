// 闭合成环
// 和数组/字符串的rotate联系起来（数组/字符串的rotate是用了reverse）
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr || head->next == nullptr)
            return head;
        int n = 1;
        ListNode* node = head;
        while(node->next != nullptr){
            ++n;
            node = node->next;
        }
        int add = n - k % n;
        if( add == n)
            return head;
        node->next = head;
        while(add){
            --add;
            node = node->next;
        }
        ListNode* res = node->next;
        node->next = nullptr;
        return res;
    }
};