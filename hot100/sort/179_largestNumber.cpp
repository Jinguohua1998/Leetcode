//思路同剑指offer 45

#include<string>
#include<vector>
#include<algorithm>

using namespace std;
//先对数字排序而不是对字符串排序，提高空间/时间效率
class Solution{
    public:
    string largestNumber(vector<int> &nums){
        sort(nums.begin(), nums.end(), [](const int& x, const int& y){
            long sx = 10, sy = 10;
            while(sx <= x)
                sx *= 10;
            while(sy <= y)
                sy *= 10;
            return sy*x + y > sx*y + x;
        });
        if(nums[0] == 0)
            return "0";
        string res;
        for(int& x : nums)
            res += to_string(x);
        return res;
    }
};


class Solution{
    public:
        string minNumber(vector<int>& nums){
            vector<string> strs;
            for(int i = 0; i < nums.size(); ++i){
                strs.push_back(to_string(nums[i]));
            }
            quickSort(strs, 0, strs.size()-1);
            string res;
            for(string s : strs)
                res += s;
            return res;
        }
        void quickSort(vector<string>& strs, int begin, int end){
            if( begin >= end){
                return;
            }
            int i = begin;
            int j = end;
            while(i < j){
                
                while(strs[j]+strs[begin] >= strs[begin]+strs[j] && i < j)
                    --j;
                while(strs[i]+strs[begin] <= strs[begin]+strs[i] && i < j)
                    ++i;
                swap(strs[i],strs[j]);
            }
            swap(strs[i], strs[begin]);
            quickSort(strs, begin, i-1);
            quickSort(strs, i+1, end);
        }
};