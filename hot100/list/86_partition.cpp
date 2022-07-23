// 思路和lc 328类似，先分割成两个链表，再组合
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//直观来说我们只需维护两个链表 small 和 large 即可，
// small 链表按顺序存储所有小于 x 的节点，large 链表按顺序存储所有大于等于 x 的节点。
// 遍历完原链表后，我们只要将 small 链表尾节点指向 large 链表的头节点即能完成对链表的分隔

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        while(pre->next != nullptr){
            if(pre->next->val >= x)
                break;
            pre = pre->next;
        }
        ListNode* node = pre;
        while(node != nullptr){
            if(node->next == nullptr)
                break;
            ListNode* currNode = node->next;
            if(currNode->val < x){
                node->next = currNode->next;
                currNode->next = pre->next;
                pre->next = currNode;
                pre = pre->next;
            }else
                // 如果已经移动节点，则
                node = node->next;
        }
        return dummyhead->next;
    }
};

