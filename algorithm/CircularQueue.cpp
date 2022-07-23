//循环队列
//用数组实现的话会浪费一个存储空间，tail指向的空间始终是空的
#include <vector>

using namespace std;

class CircularQueue{
    private:
        int n;
        vector<int> values;
        int head = 0;
        int tail = 0;
    public:
        CircularQueue(int capacity) : n(capacity), values(n){
        }
        bool enqueue(int val){
            if((tail+1)%n == head)
                return false;
            values[tail] = val;
            tail = (tail+1) % n;
            return true;
        }
        int dequeue(){
            if(head == tail)
                return -1;
            int tmp = values[head];
            head = (head+1) % n;
            return tmp;
        }



};