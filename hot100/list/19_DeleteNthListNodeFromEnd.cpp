
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 同offer 22

//快慢指针法fast、slow
//一定要注意头节点被删除的情况，所以要引入虚拟节点dummyhead
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n){
            ListNode* dummyHead = new ListNode(0);
            dummyHead->next = head;
            ListNode* first = dummyHead;
            ListNode* second = dummyHead;
            for(int i = 0; i < n + 1; ++i){
                second = second->next;
            }
            while(second != nullptr){
                first = first->next;
                second = second->next;
            }
            ListNode* delNode = first->next;
            first->next = delNode->next;
            delete delNode;

            ListNode* res = dummyHead->next;
            delete dummyHead;

            return res;
        }
};