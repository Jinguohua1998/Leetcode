#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;
        for(auto value : pushed){
            // 先压栈，防止有的还没弹出
            stk.push(value);
            while(!stk.empty() && popped[i] == stk.top()){
                stk.pop();
                ++i;
            }
        }
        if(stk.empty())
            return true;
        return false;
    }
};