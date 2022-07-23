#include <vector>
#include <stack>

using namespace std;

// 动态规划
// 这一题用动态规划更简单
// 对于数组中的每个元素，我们找出下雨后水能达到的最高位置，
// 等于两边最大高度的较小值减去当前高度的值

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) 
            return 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int size = maxRight.size();

        // 记录每个柱子左边柱子最大高度
        maxLeft[0] = height[0];
        for (int i = 1; i < size; i++) {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }
        // 记录每个柱子右边柱子最大高度
        maxRight[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }
        // 求和
        int sum = 0;
        for (int i = 0; i < size; i++) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0) sum += count;
        }
        return sum;
    }
};


//维护单调减小的栈
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> stk;
        stk.push(0);
//stack存储的是索引下标
        for(int i = 1; i < height.size(); ++i){
            // 单调栈要记住while循环
            while(!stk.empty() && height[i] > height[stk.top()]){
                int mid = stk.top();
                stk.pop();
                if(!stk.empty()){
                    int h = min(height[stk.top()], height[i]) - height[mid];
                    int w = i - stk.top() - 1;
                    res += h * w; 
                }
            }
            stk.push(i);
        }
        return res;
    }
};




//双指针
//每次遍历列的时候，还要向两边寻找最高的列rHeight、lHeight
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            // 第一个柱子和最后一个柱子不接雨水
            if (i == 0 || i == height.size() - 1) 
                continue;

            int rHeight = height[i]; // 记录右边柱子的最高高度
            int lHeight = height[i]; // 记录左边柱子的最高高度
            for (int r = i + 1; r < height.size(); r++) {
                if (height[r] > rHeight) 
                    rHeight = height[r];
            }
            for (int l = i - 1; l >= 0; l--) {
                if (height[l] > lHeight) 
                    lHeight = height[l];
            }
            int h = min(lHeight, rHeight) - height[i];
            if (h > 0) 
                sum += h;
        }
        return sum;
    }
};

