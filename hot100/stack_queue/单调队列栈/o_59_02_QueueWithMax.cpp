#include <vector>
#include <deque>

using namespace std;

class MaxQueue {
    private:
        deque<int> data;
        deque<int> maxQ; // 这里的maxQ是单调队列

    public:
        MaxQueue() {
            data.clear();
            maxQ.clear();
        }
    
        int max_value() const{
            if(maxQ.empty())
                return -1;
            return maxQ.front();
        }
    
        void push_back(int value) {
            while(!maxQ.empty() && maxQ.back() < value)
                maxQ.pop_back();
            maxQ.push_back(value);
            data.push_back(value);
        }
    
        int pop_front() {
            if(data.empty())
                return -1;
            int tmp = data.front();
            if(tmp == maxQ.front())
                maxQ.pop_front();
            data.pop_front();
            return tmp;            
        }

};
