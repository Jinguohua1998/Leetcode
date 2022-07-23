#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    int carry = 0;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    while(l1 || l2){
        int n1 = l1? l1->val : 0;
        int n2 = l2? l2->val : 0;
        int sum = n1+n2+carry;
        if(head == nullptr){
            head = tail = new ListNode(sum%10);
        }else{
//必须是tail->next = 而不能是tail = 然后 tail = tail->next,因为这时的tail->next是nullptr
            tail->next = new ListNode(sum%10);
            tail = tail->next;
        }
        carry = sum/10;
        if(l1){
            l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        }

    }
//当最高位有进位
    if(carry > 0){
        tail->next = new ListNode(1);
        tail = tail->next;
    }
    return head;
}

