#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 逆序处理首先要想到栈
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while( l1 ){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while( l2 ){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* res = nullptr;
        while( !s1.empty() || !s2.empty() ||  carry != 0){
            int n1 = s1.empty() ? 0 : s1.top();
            int n2 = s2.empty() ? 0 : s2.top();
            if(!s1.empty()){
                s1.pop();
            }
            if(!s2.empty()){
                s2.pop();
            }
            int sum = n1+n2+carry;
            carry = sum / 10;
            ListNode* tmp = new ListNode(sum % 10);
            tmp->next = res;
            res = tmp;
        }
        return res;
    }
};