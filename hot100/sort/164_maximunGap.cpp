#include <bits/stdc++.h>

using namespace std;

// 桶排序
// 设长度为 NN 的数组中最大值，最小值为 max,min，则不难发现相邻数字的最大间距不会小于 (max - min) / (N - 1)
// 元素之间的最大间距一定不会出现在某个桶的内部，而一定会出现在不同桶当中。
// 因此，在找出每个元素所在的桶之后，我们可以维护每个桶内元素的最大值与最小值。
// 随后，只需从前到后不断比较相邻的桶，用后一个桶的最小值与前一个桶的最大值之差作为两个桶的间距，最终就能得到所求的答案



class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (n - 1));
        int bucketSize = (maxVal - minVal) / d + 1;

        vector<pair<int, int>> bucket(bucketSize, {-1, -1});  // 存储 (桶内最小值，桶内最大值) 对，(-1, -1) 表示该桶是空的
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - minVal) / d;
            if (bucket[idx].first == -1) {
                bucket[idx].first = bucket[idx].second = nums[i];
            } else {
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
            }
        }

        int ret = 0;
        int prev = -1;
        for (int i = 0; i < bucketSize; i++) {
            if (bucket[i].first == -1) continue;
            if (prev != -1) {
                ret = max(ret, bucket[i].first - bucket[prev].second);
            }
            prev = i;
        }
        return ret;
    }
};