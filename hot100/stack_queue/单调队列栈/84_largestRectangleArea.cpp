#include <vector>
#include <stack>

using namespace std;

//类似于lc42 接雨水
//这里是找到左右边界（这里的边界是指比该柱子更矮的柱子）
//之后可以以该柱子为中心，并且以柱子的高度为高度形成矩形

//单调栈
//维护一个单调增的栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
//和lc42 接雨水不同的是，这里要考虑两端的边界,所有在两端加上0
        int n = heights.size();
        stack<int> stk;
        stk.push(0);
        int res = 0;
        for(int i = 1; i < n; ++i){
            while(!stk.empty() && heights[i] < heights[stk.top()]){
                int mid = stk.top();
                stk.pop();
                int w = i - stk.top() - 1;
                int h = heights[mid];
                res = max(res, w * h);
            }
            stk.push(i);
        }
        return res;
    }
};

//双指针法（类似于接雨水的双指针法）
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sum = 0;
        for (int i = 0; i < heights.size(); i++) {
            int left = i;
            int right = i;
            for (; left >= 0; left--) {
                if (heights[left] < heights[i]) break;
            }
            for (; right < heights.size(); right++) {
                if (heights[right] < heights[i]) break;
            }
            int w = right - left - 1;
            int h = heights[i];
            sum = max(sum, w * h);
        }
        return sum;
    }
};

//动态规划
//和接雨水不同的是，本题要记录记录每个柱子左边第一个小于该柱子的下标，而不是左边第一个小于该柱子的高度
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> minLeftIndex(heights.size());
        vector<int> minRightIndex(heights.size());
        int size = heights.size();

// 记录每个柱子 左边第一个小于该柱子的下标
        minLeftIndex[0] = -1; 
        for (int i = 1; i < size; i++) {
            int t = i - 1;
// 这里用while不是用if，而是不断向左寻找的过程，和接雨水不一样
            while (t >= 0 && heights[t] >= heights[i]) 
                t = minLeftIndex[t];
            minLeftIndex[i] = t;
        }

// 记录每个柱子 右边第一个小于该柱子的下标
        minRightIndex[size - 1] = size; 
        for (int i = size - 2; i >= 0; i--) {
            int t = i + 1;

            while (t < size && heights[t] >= heights[i]) 
                t = minRightIndex[t];
            minRightIndex[i] = t;
        }

        int result = 0;
        for (int i = 0; i < size; i++) {
            int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
            result = max(sum, result);
        }
        return result;
    }
};