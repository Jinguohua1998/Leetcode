#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

//集合+遍历,l空间复杂度O(N)
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        unordered_set<int> numsSet;
        int maxnum = 1, minnum = 14;
        for(auto num : nums){
            if(num == 0)
                continue;
            if(numsSet.find(num) != numsSet.end())
                return false;
            numsSet.insert(num);
            maxnum = max(maxnum, num);
            minnum = min(minnum, num);
        }
        return maxnum - minnum < 5;
    }
};

//排序+遍历，时间复杂度O(NlnN)
class Solution2 {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int joker = 0;
//记录大小王的数量，也就是0的数量
        for(int i = 0; i < 5; ++i){
            if(nums[i] == 0)
                ++joker;
            else if(i < 4 && nums[i] == nums[i+1])
                return false; 
        }
        return nums[4] - nums[joker] < 5;
    }
};