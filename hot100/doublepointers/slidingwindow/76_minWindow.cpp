#include <string>
#include <unordered_map>

using namespace std;

//哈希表+双指针
//在这一题中，以滑动窗口的右端点为循环变量

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> smap, tmap;
// 定义两个map，类似于lc 30
        int cnt = 0;
// cnt表示匹配的字符个数
        string res;
        for(auto ch : t)
            ++tmap[ch];
        for(int i = 0, j = 0; j < s.size(); ++j){
//i是左指针，j是右指针
            ++smap[s[j]];
            if(smap[s[j]] <= tmap[s[j]])
                ++cnt;
            while(smap[s[i]] > tmap[s[i]]){
                --smap[s[i]];
                ++i;
//左指针右移
            }
            if(cnt == t.size()){
                if(res.empty() || j-i+1 < res.size())
                    res = s.substr(i, j-i+1);
            }
        }
        return res;
    }
};