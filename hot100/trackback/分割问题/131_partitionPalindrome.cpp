//判断是否回文参见 lc 5
#include <vector>
#include <string>

using namespace std;

// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
// 返回 s 所有可能的分割方案。

//判断是否回文串可以用1. 双指针（动态规划）或者2. 中心扩展法

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path; 
    void backtrack (const string& s, int startIndex) {
        if (startIndex == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {  
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
                backtrack(s, i + 1); 
                path.pop_back(); 
            } 
        }
    }
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtrack(s, 0);
        return result;
    }
};