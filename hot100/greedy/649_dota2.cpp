#include <string>

using namespace std;

// 模拟法

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
//R = true表示本轮循环结束后，字符串里依然有R。D同理
        bool R = true, D = true;
// flag > 0则表示到目前为止R更多，flag < 0则表示到目前为止D更多
// flag的目的主要是判断当前的R 或者 D该不该禁言
        int flag = 0;
        while(R && D){
            R = false;
            D = false;
            for(int i = 0; i < n; ++i){
                if(senate[i] == 'R'){
                    if(flag < 0)
//被禁言的参议员被设置为0
                        senate[i] = 0;
                    else
                        R = true;
                    ++flag;
                }
                if(senate[i] == 'D'){
                    if(flag > 0)
                        senate[i] = 0;
                    else
                        D = true;
                    --flag;
                }
            }
        }
        return R == true ? "Radiant" : "Dire"; 
    }
};