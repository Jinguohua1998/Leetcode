#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
//哈希表
int longestConsecutive(vector<int>& nums){
    if(nums.size() == 0)
        return 0;
//边界条件检测，vector不含有数字
    unordered_set<int> numSet;
    for(const int& num: nums)
        numSet.insert(num);

    int longestSeq = 1;
    
    for(const int& num: numSet){
        if(numSet.find(num-1) == numSet.end()){
//set中查找某项：count返回个数，find返回迭代器
//只有当一个数是连续序列的第一个数的情况下才会进入内层循环
            int currentNum = num;
            int currentStreak = 1;
            while(numSet.find(++currentNum) != numSet.end()){
//此处不可以用++num，因为这样会改变vector中num的值
                ++ currentStreak;
            }
            longestSeq = currentStreak > longestSeq ? currentStreak : longestSeq;
        }
    }
    return longestSeq;
}

int main(){
    vector<int> a{1,2,3,5,6,7,8,9};
    cout << longestConsecutive(a);
}