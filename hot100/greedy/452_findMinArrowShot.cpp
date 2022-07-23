#include <vector>
#include <algorithm>

using namespace std;

//思路和lc435类似
class Solution {
private:
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int res = 1;
        for(int i = 1; i < points.size(); ++i){
            if(points[i][0] > points[i-1][1])
                ++res;
            else
                points[i][1] = min(points[i][1], points[i-1][1]); // 要加上min
        }
        return res;
    }
};