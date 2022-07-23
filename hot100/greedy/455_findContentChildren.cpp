#include <algorithm>
#include <vector>

using namespace std;

// 用小饼干先喂饱小胃口

class Solution{
public:
    int findContentChildren(vector<int>& g, vector<int>& s){
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0; // index表示孩子的索引
        // 以饼干的索引作为主循环
        for(int i = 0; i < s.size() && index < g.size(); ++i){
            if(g[index] <= s[i]){
                ++index;
            }
        }
        return index;
    }
};