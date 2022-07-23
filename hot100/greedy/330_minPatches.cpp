#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 覆盖区间是[0, x-1]，所以x的初始值为1
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long x = 1;
        int length = nums.size(), index = 0;
        while(x <= n){
            if(index < length && nums[index] <= x){
                x += nums[index];
                ++index;
            }else{  // 目前覆盖不到x，只能覆盖到[0, x - 1]，所以要加上x，覆盖范围变成[0, 2*x - 1]
                x <<= 1;
                ++patches;
            }
        }
        return patches;
    }
};