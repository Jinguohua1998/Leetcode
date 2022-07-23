#include <string>

using namespace std;

class Solution {
private:
    void getNext(int* next, const string& p){
        next[0] = 0;
        int n = p.size();
        for(int i = 1, j = 0; i < n; ++i){
            while(j > 0 && p[i] != p[j]){
                j = next[j-1];
            }
            if(p[i] == p[j])
                ++j;
            next[i] = j;
        }
    }
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n == 0)
            return false;
        int next[n];
        getNext(next, s);
        if(next[n-1] != 0 && n % (n-next[n-1]) == 0){
            return true;
        }
        return false;
    }
};