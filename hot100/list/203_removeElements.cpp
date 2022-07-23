struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* node = dummyhead;
        while(node->next != nullptr){
            if(node->next->val == val){
                auto tmp = node->next;
                node->next = tmp->next;
                delete tmp;
            }else{
                node = node->next;
            }
//这里必须要加else，因为如果已经删除了节点node->next可能是nullptr
        }
        head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};