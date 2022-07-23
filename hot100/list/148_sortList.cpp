//思路类似于lc23
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//递归法
//1.分割 cut 环节
//2.合并 merge 环节
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
//用快慢指针确定链表的中间节点
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            // 注意 ：这里要判断fast->next->next
            slow = slow->next;
            fast = fast->next->next;
        }
//1.分割
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(tmp);
//2.合并
        return merge(left, right);
    }

// merge的作用是合并两个有序链表
// 也可以用递归的方法写
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummyhead = new ListNode(0);
        ListNode* tmp = dummyhead;
        while(left != nullptr && right != nullptr){
            if(left->val < right->val){
                tmp->next = left;
                left = left->next;
            }
            else{
//这里要注意可能出现重复的数字，即right->val == left->val
//直接使用条件else if(right->val < left->val)会报错
                tmp->next = right;
                right = right->next;
            }
            tmp = tmp->next;
        }
        tmp->next = left ? left : right;
        return dummyhead->next;
    }
};

//迭代法
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        int len = 0;
        ListNode* node = head;
        while(node != nullptr){
            node = node->next;
            ++len;
        }
        ListNode* dummyhead = new ListNode(0, head);
        for(int subLen = 1; subLen < len; subLen <<= 1){
            ListNode* prev = dummyhead, *cur = dummyhead->next;
            while(cur != nullptr){
                ListNode* head1 = cur;
                for(int i = 1; i < subLen && cur->next != nullptr; ++i){
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for(int i = 1; i < subLen && cur != nullptr; ++i){
                    cur = cur->next;
                }
                ListNode* next = nullptr;
                if(cur != nullptr){
                    next = cur->next;
                    cur->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while(prev->next != nullptr)
                    prev = prev->next;
                cur = next;

            }
        }
        return dummyhead->next;
    }

//此处的merge和上一个class中完全一样：合并两个有序链表
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummyhead = new ListNode(0);
        ListNode* tmp = dummyhead;
        while(left != nullptr && right != nullptr){
            if(left->val < right->val){
                tmp->next = left;
                left = left->next;
            }
            else{
//这里要注意可能出现重复的数字，即right->val == left->val
//直接使用条件else if(right->val < left->val)会报错
                tmp->next = right;
                right = right->next;
            }
            tmp = tmp->next;
        }
        tmp->next = left ? left : right;
        return dummyhead->next;
    }

};