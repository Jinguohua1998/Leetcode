/*
将值为i的元素放入i号桶，最后依次把桶里的元素倒出来。
算法思想：
设置一个定量的数组当作空桶子。
寻访序列，并且把项目一个一个放到对应的桶子去。
对每个不是空的桶子进行排序。
从不是空的桶子里把项目再放回原来的序列中。
*/
#include <vector>
#include <algorithm>

using namespace std;

#define OFFSET 0
#define STEPSIZE 3
#define MAXNUM 100000

vector<int> bucketSort(vector<int>& nums){
    int n = nums.size();
    //第一步：将所有数据转换成一定区间范围内的
    for(int i = 0; i < n; ++i)
        nums[i] += OFFSET;
    
    //第二步 ： 观察数据，设置桶的个数（步长）
    int step = STEPSIZE;
    int bucketSize = MAXNUM/step;

    vector<vector<int>> buckets(bucketSize+1, vector<int>(n));

    //第三步 ： 分桶
    for(int i = 0; i < n; ++i){
        int bucketIndex = nums[i] / step;
        buckets[bucketIndex].push_back(nums[i]);
    }

    //第四步 ：对每个桶进行排序
    for(int i = 0; i <= bucketSize; ++i){
        stable_sort(buckets[i].begin(), buckets[i].end());
    }

    // 第五步：从桶里依次取出来
    vector<int> res(n);
    int index = 0;
    for(int i = 0; i <= bucketSize; ++i){
        for(int num : buckets[i])
            res[index++] = num - OFFSET;
    }
    return res;
}