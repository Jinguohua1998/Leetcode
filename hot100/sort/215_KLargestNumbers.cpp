//和offer40 完全一样
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <functional> //functor: greater

using namespace std;

// 优先队列
// 用greater<int>的优先队列，堆顶是最小的元素，也就是小顶堆，less<int>相反
class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> Q;

        for(int i = 0; i < k; ++i){
            Q.push(nums[i]);
        }
        for(int i = k; i < nums.size(); ++i){
            if(nums[i] > Q.top()){
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();
    }
};



//基于快排的partition
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
            return QuickSort(nums, n-k, 0 , nums.size()-1);
        }

    private:
        int QuickSort(vector<int>& nums, int k, int l, int r){
            int i = l, j = r;
            while(i < j){
                while(i < j && nums[j] >= nums[l])
                    --j;
//保证nums[j]是小于nums[l]的
                while(i < j && nums[i] <= nums[l])
                    ++i;
                swap(nums[i], nums[j]);
            }
            swap(nums[i], nums[l]);
            if(i == k)
                return nums[i];
            else if( i > k)
                return QuickSort(nums, k, l, i-1);
            else
                return QuickSort(nums, k, i+1, r);
    }
};

class Solution2 {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

// 维护一个最小堆
class Solution4 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> vecHeap(nums.begin(), nums.begin() + k);
        make_heap(vecHeap.begin(), vecHeap.end(), greater<int>());
        for(int i = k; i < nums.size(); ++i){
            if(nums[i] > vecHeap.front()){
                pop_heap(vecHeap.begin(), vecHeap.end());
                vecHeap.pop_back();
                vecHeap.push_back(nums[i]);
                push_heap(vecHeap.begin(), vecHeap.end());
            }
        }
        return vecHeap.front();
    }
};