//双指针法
#include <vector>
#include <climits>
#include <stack>

using namespace std;
// 从左到右维护最大值，寻找右边界end
// 在进入右段之前，那么遍历到的nums[i]都是小于max的，我们要求的end就是遍历中最后一个小于max元素的位置
// 从右到左维护最小值，寻找左边界start
// 同理

// 也就是说要找到一个end，end左边的数字都小于max
// 找到一个start， start右边的数字都大于min

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;
        int maxVal = INT_MIN, minVal = INT_MAX;
        for(int i = 0; i < n; ++i){
            if(nums[i] < maxVal){
                right = i;
            }else{
                maxVal = nums[i];
            }
            if(nums[n-1-i] > minVal){
                left = n -i - 1;
            }else{
                minVal = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};


//单调栈
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int left = nums.size()-1, right = 0;

        // 维护一个递增栈
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[i] < nums[st.top()]){
                left = min(left, st.top());
                st.pop();
            }
            st.push(i);
        }

        // 维护一个递减栈
        for(int i = nums.size() - 1; i >= 0; i--){ 
            while(!st.empty() && nums[i] > nums[st.top()]){
                right = max(right, st.top());
                st.pop();
            }
            st.push(i);
        }
        
        return max(0, right - left + 1);
    }
};
