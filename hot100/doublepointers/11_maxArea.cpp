#include <vector>
#include <algorithm>
using namespace std;
//双指针法
int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while(l < r){
        int area = (r-l)*min(height[l], height[r]);
        ans = max(area, ans);
        if(l < r)
            ++l;
        else
            --r;
    }
    return ans;
}