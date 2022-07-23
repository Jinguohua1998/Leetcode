#include <bits/stdc++.h>

using namespace std;

// 求最长前缀回文串

class Solution {
private:
    void getNext(const string& s, vector<int>& next){
        int n = s.size();
        next[0] = 0;
        for(int i = 1, j = 0; i < n; ++i){
        // i是后缀的最后一个字符索引下标，j是前缀的第一个字符的索引下标
            while(j > 0 && s[i] != s[j])
                j = next[j-1];
            if(s[i] == s[j])
                ++j;
            next[i] = j;
        }
    }
public:
    string shortestPalindrome(string s) {
        if(s == "")
            return s;
        int n = s.size();
        vector<int> next(n, 0); 
        getNext(s, next);
        int index = 0;
        for(int i = n-1; i >= 0; --i){
            while(index > 0 && s[i] != s[index])
                index = next[index-1];
            if(s[i] == s[index])
                ++index;
        }
        string add = (index == n  ? "" : s.substr(index));
        reverse(add.begin(), add.end());
        return add + s;
    }
};