//类似于单调栈的思想
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

// 这里直接用vector代替stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto asteroid : asteroids){
            bool flag = 1; // 这里的flag表示当前的asteroid是否可以压入栈中
            while(res.size() != 0 && asteroid <0 && res.back() > 0){
                if(abs(asteroid) < abs(res.back())){
                    flag = 0;
                    break;
                }
                else if(abs(asteroid) == abs(res.back())){
                    flag = 0;
                    res.pop_back();
                    break;
                }else{
                    res.pop_back();
                }
            }
            if(flag)
                res.push_back(asteroid);
        }
        return res;
    }
};