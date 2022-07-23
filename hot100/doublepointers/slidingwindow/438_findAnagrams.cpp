#include <string>
#include <vector>

using namespace std;
//思路类似于lc76
//定义两个map，一个记录s，一个记录p
//再定义一个count记录滑动窗口下s与p匹配的个数
class Solution{
public:
    vector<int> findAnagrams(string s, string p){
        int sLen = s.size(), pLen = p.size();
        if(sLen < pLen)
            return {};
        int smap[26] = {0};
        int pmap[26] = {0};
        int count = 0;
        vector<int> res;
        for(int i = 0; i < pLen; ++i){
            ++pmap[p[i]-'a'];
        }
        for(int i = 0; i < pLen; ++i){
            ++smap[s[i]-'a'];
            if(smap[s[i] -'a'] <= pmap[s[i]-'a'])
                ++count;
        }
        if(count == pLen)
            res.push_back(0);
        for(int i = 1; i <sLen-pLen+1; ++i){
            if(smap[s[i-1] -'a'] <= pmap[s[i-1]-'a'])
                --count;
            --smap[s[i-1] -'a'];
            ++smap[s[i+pLen-1]-'a'];
            if(smap[s[i+pLen-1]-'a'] <= pmap[s[i+pLen-1]-'a'])
                ++count;
            if(count == pLen)
                res.push_back(i);
        }
        return res;
    }
};