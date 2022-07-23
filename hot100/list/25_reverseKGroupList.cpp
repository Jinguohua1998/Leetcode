// 翻转链表的升级版
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代法
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;

        ListNode* pre = dummyhead;
        ListNode* end = dummyhead;

        while(end->next != nullptr){
            for(int i = 0; i < k && end != nullptr; ++i){
                end = end->next;
            }
            //如果不到K个节点，则break
            if( end == nullptr)
                break;
            ListNode* start = pre->next;
            ListNode* next = end->next;
            end->next = nullptr;
            pre->next = reverse(pre->next);
            // reverse函数只检查链表尾部有没有断开，而头部没有断开没有关系
            start->next = next;
            end = pre = start;
        }
        return dummyhead->next;
    }

    // 翻转链表
    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};