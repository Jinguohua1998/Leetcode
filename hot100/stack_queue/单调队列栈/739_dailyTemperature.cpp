//单调栈
//维护一个单调减的栈，遇到大于栈顶元素的数，则弹出栈顶
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = 0; i < n; ++i){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int index = s.top();
                res[index] = i - index;
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};