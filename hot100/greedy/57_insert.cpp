#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int left = newInterval[0];
        int right = newInterval[1];
        // 这里的left，right不仅仅指的是要插入的newInterval的左右边界，也指要插入区间和其他区间合并后的左右边界
        bool placed = false;
        for(const auto& interval : intervals){
            if(interval[0] > right){
                if(!placed){
                    res.push_back({left, right});
                    placed = true;
                }
                res.push_back(interval);
            }else if(interval[1] < left){
                res.push_back(interval);
            }else{
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            res.push_back({left, right});
        }
        return res;
    }
};