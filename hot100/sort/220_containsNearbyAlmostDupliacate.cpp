#include <bits/stdc++.h>

using namespace std;

// 滑动窗口 + 有序集合
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> st;
        for (int i = 0; i < nums.size(); i++) {
            auto lb = st.lower_bound((long)nums[i] - t);
            if (lb != st.end() && *lb <= (long)nums[i] + t) return true;
            st.insert(nums[i]);
            if (i >= k) st.erase(nums[i - k]);
        }
        return 0;
    }
};

// 桶排序
/*
我们按照元素的大小进行分桶，维护一个滑动窗口内的元素对应的元素。

对于元素 xx，其影响的区间为 [x - t, x + t]。于是我们可以设定桶的大小为 t + 1。
如果两个元素同属一个桶，那么这两个元素必然符合条件。如果两个元素属于相邻桶，那么我们需要校验这两个元素是否差值不超过 t。
如果两个元素既不属于同一个桶，也不属于相邻桶，那么这两个元素必然不符合条件。

*/
class Solution {
public:
    int getID(int x, long w) {
        return x < 0 ? (x + 1l) / w - 1 : x / w;
        // 给负数分桶的时候需要注意，可以举例 -4 -3 -2 -1 0 bucket size = 4来处理
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long x = nums[i];
            int id = getID(x, t + 1l);
            if (mp.count(id)) {
                return true;
            }
            if (mp.count(id - 1) && abs(x - mp[id - 1]) <= t) {
                return true;
            }
            if (mp.count(id + 1) && abs(x - mp[id + 1]) <= t) {
                return true;
            }
            mp[id] = x;
            if (i >= k) {
                mp.erase(getID(nums[i - k], t + 1l));
            }
        }
        return false;
    }
};