#include <bits/stdc++.h>

using namespace std;

// 优先队列
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> max; // 大顶堆
    priority_queue<int, vector<int>, greater<int>> min; // 小顶堆
    MedianFinder(){
        while(!max.empty())
            max.pop();
        while(!min.empty())
            min.pop();
    }
    
    void addNum(int num) {
        if((min.size() + max.size()) & 1){
            //插入前总数为奇数个，要放进max中
            if(!min.empty() && min.top() < num){
                min.push(num);
                num = min.top();
                min.pop();
            }
            max.push(num);
        }else{
            //插入前总数为偶数个，要将多出的那个放进min中
            if(!max.empty() && max.top() > num){
                max.push(num);
                num = max.top();
                max.pop();
            }
            min.push(num);
        }

    }
    
    double findMedian() {
        if((min.size() + max.size()) & 1){
            return min.top();
        }else{
            return (double) (min.top() + max.top())/2;
        }
    }
};




//cpp中heap的用法https://www.cnblogs.com/bandaoyu/p/14624932.html
class MedianFinder{
    public:
        MedianFinder(){
            max.clear();
            min.clear();
        }

        void addNum(int num){
            if(((max.size()+min.size()) & 1) == 0){
//插入前总数为偶数个，要将多出的那个放进min中
                if(max.size() > 0 && num < max[0]){
                    max.push_back(num);
                    push_heap(max.begin(), max.end(), less<int>());
                    num = max[0];
                    pop_heap(max.begin(), max.end(), less<int>());
                    max.pop_back();
                }
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
            }else{
//插入前总数为奇数个，要放进max中
                if((min.size() > 0 && num > min[0])){
                    min.push_back(num);
                    push_heap(min.begin(), min.end(), greater<int>());
                    num = min[0];
                    pop_heap(min.begin(), min.end(), greater<int>());
                    min.pop_back();
                }
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
            }
        }

        double findMedian(){
            if(((max.size() + min.size()) & 1) == 0)
                return double(max[0] + min[0])/2;
            else
                return min[0];
        }

    private:
        vector<int> max;
        vector<int> min;
};