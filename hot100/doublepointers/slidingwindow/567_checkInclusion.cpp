#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int cnt = 0;
        if (m > n) {
            return false;
        }
        int smap[26] = {0};
        int pmap[26] = {0};
        for (int i = 0; i < m; ++i) {
            ++pmap[s1[i] - 'a'];
        }
        for (int i = 0; i < m; ++i) {
            ++smap[s2[i] - 'a'];
            if(smap[s2[i] - 'a'] <= pmap[s2[i] - 'a'])
                ++cnt;
        }
        if (cnt == m) {
            return true;
        }
        for (int i = 1; i < n-m+1; ++i) {
            if(smap[s2[i-1] - 'a'] <= pmap[s2[i-1] - 'a'])
                --cnt;
            --smap[s2[i-1] - 'a'];
            ++smap[s2[i+m-1] - 'a'];
            if(smap[s2[i+m-1] - 'a'] <= pmap[s2[i+m-1] - 'a'])
                ++cnt;

            if (cnt == m) 
                return true;
        }
        return false;
    }
};