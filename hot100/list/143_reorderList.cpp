#include <deque>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 把链表放进数组中，然后通过双指针法，一前一后，来遍历数组，构造链表。
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* cur = head;
        if (cur == nullptr) return;
        while(cur != nullptr) {
            vec.push_back(cur);
            cur = cur->next;
        }
        cur = head;
        int i = 1;
        int j = vec.size() - 1;  // i j为之前前后的双指针
        int count = 0; // 计数，偶数去后面，奇数取前面
        while (i <= j) {
            if (count % 2 == 0) {
                cur->next = vec[j];
                j--;
            } else {
                cur->next = vec[i];
                i++;
            }
            cur = cur->next;
            count++;
        }
        cur->next = nullptr; // 注意结尾
    }
};

// 把链表放进双向队列，然后通过双向队列一前一后弹出数据，来构造新的链表。
class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> que;
        ListNode* cur = head;
        if (cur == nullptr) return;

        while(cur->next != nullptr) {
            que.push_back(cur->next);
            cur = cur->next;
        }

        cur = head;
        int count = 0; // 计数，偶数去后面，奇数取前面
        ListNode* node;
        while(que.size()) {
            if (count % 2 == 0) {
                node = que.back();
                que.pop_back();
            } else {
                node = que.front();
                que.pop_front();
            }
            count++;
            cur->next = node;
            cur = cur->next;
        }
        cur->next = nullptr; // 注意结尾
    }
};



// 先反转链表再合并两个链表
// 空间复杂度为O（1）
// 但是代码比较复杂
class Solution {
private:
    // 反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            ListNode* temp = cur->next;  
            cur->next = pre; 
            pre = cur;
            cur = temp;
        }
        return pre;
    }
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        // 使用快慢指针法，将链表分成长度均等的两个链表head1和head2
        // 如果总链表长度为奇数，则head1相对head2多一个节点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = nullptr;

        // 对head2进行翻转
        head2 = reverseList(head2);

        // 将head1和head2交替合并成新的链表head
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        ListNode* cur = head;
        cur1 = cur1->next;
        int count = 0; // 偶数取head2的元素，奇数取head1的元素
        while (cur1 && cur2) {
            if (count % 2 == 0) {
                cur->next = cur2;
                cur2 = cur2->next;
            } else {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            count++;
            cur = cur->next;
        }
        if (cur2 != nullptr) { // 处理结尾
            cur->next = cur2;
        }
        if (cur1 != nullptr) {
            cur->next = cur1;
        }
    }
};