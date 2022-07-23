#include <unordered_map>

using namespace std;

//hash表+双向链表（注意 ： 这里是双向链表）

struct DLinkedNode{
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr){}
    DLinkedNode(int key, int value): key(key), value(value), prev(nullptr), next(nullptr){}
};

class LRUCache {

private:
    unordered_map<int, DLinkedNode*> cache; // 这里的unordered_map比较关键，减小了时间复杂度
    DLinkedNode* dummyhead;
    DLinkedNode* dummytail;
    int size;
    int capacity;

    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode* node){
        node->next = dummyhead->next;
        node->prev = dummyhead;
        dummyhead->next->prev = node;
        dummyhead->next = node;
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = dummytail->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return node;
    }

public:
    LRUCache(int capacity) : size(0), capacity(capacity) {
        dummyhead = new DLinkedNode();
        dummytail = new DLinkedNode();
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        DLinkedNode* node = cache[key];
        moveToHead(node);
//如果找到，将该节点移动到链表头部
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            if(size == capacity){
                DLinkedNode* node = removeTail();
                cache.erase(node->key);
//不能忘了在hash表中删除对应项
                delete node;
                --size;
            }
            ++size;
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
        }else{
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
};
