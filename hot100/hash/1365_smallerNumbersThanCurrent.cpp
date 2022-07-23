#include <vector>
#include <algorithm>

using namespace std;

//倒叙遍历的思想
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        int n = nums.size();
        sort(vec.begin(), vec.end());
        int hash[101];
        for(int i = n-1; i >= 0; --i){
            hash[vec[i]] = i;
        }
        for(int i = 0; i < n; ++i){
            vec[i] = hash[nums[i]];
        }
        return vec;
    }
};