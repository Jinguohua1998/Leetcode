#include <string>

using namespace std;

/*
前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串。
后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串。
*/

class Solution {
private:
    void getNext(int* next, const string& p){
        int n = p.size();
        next[0] = 0;
        for(int i = 1, j = 0; i < n; ++i){
//i是后缀的最后一个字符索引下标，j是前缀的第一个字符的索引下标
            while(j > 0 && p[i] != p[j])
                j = next[j-1];
            if(p[i] == p[j])
                ++j;
            next[i] = j;
        }
    }
public: // haystack是待匹配字符串，needle是模式字符串
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        int m = haystack.size(), n = needle.size();
        int next[n];
// next[i]表示needle[i]结尾的字符串的前后缀公共字符串长度
        getNext(next, needle);
        for(int i = 0, j = 0; i < m; ++i){
//i是haystack的索引，j是needle的索引
            while(j > 0 && haystack[i] != needle[j])
                j = next[j-1];
            if(haystack[i] == needle[j])
                ++j;
            if(j == n)
                return i - n + 1;
        }
        return -1;
    }
};