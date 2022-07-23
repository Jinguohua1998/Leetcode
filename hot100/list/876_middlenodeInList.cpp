struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr ) {
//如果节点个数为奇数，则返回的slow是后面的中间节点
//如果加上fast->next->next != nullptr如果节点个数为偶数，则返回的slow是前面的中间节点
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};