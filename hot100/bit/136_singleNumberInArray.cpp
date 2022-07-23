#include <vector>
#include <iostream>

using namespace std;

int singleNumber(const vector<int>& nums){
    int single = 0;
    for (auto num : nums)
        single ^= num;
//异或的位运算，a ^ a = 0, 0^a =a
    return single;
}

int main(){
    vector<int> nums = {1,1,2,2,3};
    cout << singleNumber(nums);
}