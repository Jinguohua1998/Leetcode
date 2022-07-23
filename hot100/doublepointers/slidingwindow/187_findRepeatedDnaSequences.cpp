#include <bits/stdc++.h>

using namespace std;

// 哈希表 + 滑动窗口 + 位运算

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> res;
        int L = 10;
        unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        if(n <= L)
            return res;
        int x = 0;
        for(int i = 0; i < L - 1; ++i){
            x = (x << 2) | bin[s[i]];
        }
        unordered_map<int, int> cnt;
        for (int i = 0; i <= n - L; ++i) {
            x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << (L * 2)) - 1);
            if (++cnt[x] == 2) {
                res.push_back(s.substr(i, L));
            }
        }
        return res;
    }
};