#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

// 前K个高频元素
// 排序算法：桶排序，堆排序（优先队列）

// 优先队列

// 大顶堆（堆头是最大元素），小顶堆（堆头是最小元素），
// 如果懒得自己实现的话，就直接用priority_queue（优先级队列）就可以了，
// 底层实现都是一样的，从小到大排就是小顶堆，从大到小排就是大顶堆

// 左大于右就会建立小顶堆，反而建立大顶堆。
// 而我们在写快排的cmp函数的时候，return left>right 就是从大到小，return left<right 就是从小到大。


class Solution {

    static bool cmp(pair<int, int>& m, pair<int, int>& n){
        return m.second > n.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for(auto val : nums)
            ++occurrences[val];
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            decltype(&cmp)> q(cmp);
//lambda表达式不可以用decltype
//这里传进去的是函数指针
        for(auto& member : occurrences){
            if(q.size() == k){
                if(member.second > q.top().second){
                    q.pop();
                    q.emplace(member.first, member.second);
                }
            }else{
                q.emplace(member.first, member.second);
            }
        }

        vector<int> res;
        while (!q.empty()){
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};


//桶排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int maxCount = 0;
        unordered_map<int, int> numCount;
        for(auto num : nums){
            ++numCount[num];
            maxCount = max(maxCount, numCount[num]);
        }

        vector<vector<int>> buckets(maxCount + 1);
        for(auto member : numCount){
            buckets[member.second].push_back(member.first);
        }

        vector<int> res;
        for(int i = maxCount; i >= 0; --i){
            if(!k)
                break;
            if(!buckets[i].size())
                continue;
            for(int j = 0; j < buckets[i].size(); ++j){
                res.push_back(buckets[i][j]);
                --k;
            }
        }
        return res;
    }
};


class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k（priority_queue的底层就是heap）
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

