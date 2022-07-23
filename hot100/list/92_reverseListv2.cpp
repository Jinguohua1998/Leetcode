struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

//头插法
//链表问题一定要考虑用dummyhead
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        for(int i = 0; i < left-1; ++i)
            pre = pre->next;
        ListNode* cur = pre->next;
        
        for(int i = 0; i < right-left; ++i){
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummyhead->next;
    }
};