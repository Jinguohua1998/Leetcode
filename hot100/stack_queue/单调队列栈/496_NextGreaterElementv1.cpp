#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> stk;
//这里的stack存储值而不是索引，更好一点
        for(int i = 0; i < nums2.size(); ++i){
            int num = nums2[i];
            while(!stk.empty() && stk.top() < num){
                map[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); ++i){
            res[i] = map.find(nums1[i]) != map.end() ? map[nums1[i]] : -1;
        }
        return res;
    }
};