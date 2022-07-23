//思路类似于lc148
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 归并排序（递归）
// 和顺序合并相比，时间复杂度更低
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
//这个函数也可以用递归写
        if((!a) || (!b))
            return a ? a : b;
        ListNode* dummyhead = new ListNode(-1);
        ListNode* node = dummyhead;
        while(a && b){
            if(a->val < b->val){
                node->next = a;
                a = a->next;
            }else{
                node->next = b;
                b = b->next;
            }
            node = node->next; 
        }
        node->next = a ? a : b;
        return dummyhead->next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l == r)
            return lists[l];
        if(l > r)
            return nullptr;
        int mid = l + ((r-l) >> 1);
// 这里的位运算一定要加括号
// 因为位运算的优先级低于加减号
// 和普通的归并排序相比，这里的merge递归函数写在了mergeTwoLists里面，两步合并为一步
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
};

//归并排序（迭代）
//空间复杂度为O(1)
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
//这个函数也可以用递归写
            if((!a) || (!b))
                return a ? a : b;
            ListNode* dummyhead = new ListNode(-1);
            ListNode* node = dummyhead;
            while(a && b){
                if(a->val < b->val){
                    node->next = a;
                    a = a->next;
                }else{
                    node->next = b;
                    b = b->next;
                }
                node = node->next; 
            }
            node->next = a ? a : b;
            return dummyhead->next;
        }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return nullptr;
        while(n > 1){
            int index = 0;
            for(int i = 0; i < n; i += 2){
                if( i == n-1)
                    lists[index++] = lists[i];
                else
                    lists[index++] = mergeTwoLists(lists[i], lists[i+1]);
            }
            n = index;
        }
        return lists[0];
    }
};


//顺序合并
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for(auto node : lists)
            res = mergeTwoLists(res, node);
        return res;
    }
private:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
//也可以用递归写
            if((!a) || (!b))
                return a ? a : b;
            ListNode* dummyhead = new ListNode(-1);
            ListNode* node = dummyhead;
            while(a && b){
                if(a->val < b->val){
                    node->next = a;
                    a = a->next;
                }else{
                    node->next = b;
                    b = b->next;
                }
                node = node->next; 
            }
            node->next = a ? a : b;
            return dummyhead->next;
        }
};

//优先队列

class Solution {
private:
    struct Status{
        ListNode* ptr;
        bool operator < (const Status& rhs) const{
            return ptr->val > rhs.ptr->val;
        }
        Status(ListNode* node): ptr(node){}
    };
    priority_queue<Status> q;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto node : lists){
            if(node)
                q.emplace(node);
        }
        ListNode* dummyhead = new ListNode(-1);
        ListNode* node = dummyhead;
        while(!q.empty()){
            auto tmp = q.top();
            q.pop();
            if(tmp.ptr->next)
                q.emplace(tmp.ptr->next);
            node->next = tmp.ptr;
            node = node->next;
        }
        return dummyhead->next;
    }
};


