#include <string>
#include <vector>
#include <iostream>

using namespace std;

//一维数组

//记忆KMP算法的时候要记住getNext以及strStr的两个while循环放在外面
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
public:
    int strStr(string s, string p) {
        if(p.size() == 0)
            return 0;
        int m = s.size(), n = p.size();
        int next[n];
        getNext(next, p);
        for(int i = 0, j = 0; i < m; ++i){
//i是s的索引，j是p的索引
            while(j > 0 && s[i] != p[j])
                j = next[j-1];
            if(s[i] == p[j])
                ++j;
            if(j == n)
                return (i - p.size() + 1);
        }
        return -1;
    }
};

int main(){
    string s("aabaabaaf");
    string p("aabaafh");

}

