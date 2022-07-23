// lc 189轮转数组也是同样的方法
#include <string>
#include <algorithm>

using namespace std;

class Solution{
    public:
        string reverseLeftWords(string s, int n){
            return s.substr(n, s.length() - n) + s.substr(0, n);
        }
};

//空间复杂度更低
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};