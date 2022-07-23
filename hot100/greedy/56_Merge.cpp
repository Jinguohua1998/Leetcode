//合并区间
//要用到排序
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if(intervals.size() == 0)
                return {};
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> res;
            for(int i = 0; i < intervals.size(); ++i){
                int left = intervals[i][0], right = intervals[i][1];
                if(!res.size() || left > res.back()[1])
//vector的最后一个元素，back()
                    res.push_back({left, right});
                else    
                    res.back()[1] = max(right, res.back()[1]);
            }
            return res;
    }
};