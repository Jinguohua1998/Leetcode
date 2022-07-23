#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 2;
        int sum = 3;
        vector<vector<int>> res;
        for(; left < right; ++left){
            if(left > 1)
                sum -= (left-1);

            while(sum < target){
                ++right;
                sum += right;
            }

            if(sum == target && left < right){
                vector<int> tmp;
                for(int i = left; i <= right; ++i)
                    tmp.push_back(i);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

//滑动窗口（双指针）
class Solution{
    public:
        vector<vector<int>> findContinuousSequence(int target){
            int left = 1, right = 2, sum = 3;
            vector<vector<int>> res;
            while( left < right){
                if(sum == target){
                    vector<int> arr;
                    for(int k = left; k <= right; ++k)
                        arr.push_back(k);
                    res.push_back(arr);
                }
//sum == target之后left还需要-1，所以需要sum >= target
                if(sum >= target){
                    sum -= left;
                    ++left;
                }else{
                    ++right;
                    sum += right;
                }
            }
            return res;
        }
};

