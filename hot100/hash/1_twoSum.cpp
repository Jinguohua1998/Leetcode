#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumv2(vector<int>& nums, int target){
    int n = nums.size();
    unordered_map<int, int> hashtable;
    for(int i = 0; i < n; ++i){
        auto it = hashtable.find(target-nums[i]);
        if(it != hashtable.end()){
            return {it->second, i};
        }
        hashtable[nums[i]] = i;
    }
    return {};
}