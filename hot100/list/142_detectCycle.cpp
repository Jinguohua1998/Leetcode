//快慢指针
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 因为fast每次走两个节点，而slow每次只走一个节点
// 所以fast必定在slow走完一个环之前就能追上slow
// 所以slow走的路程是a + b
// 相遇前： 慢指针走的路程*2 = 快指针走的路程
//                2(a + b) = a + b + n*(b + c)
// a = c + (n-1)(b+c)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(true){
            if(fast == nullptr || fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
                break;
        }
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;

    }
};