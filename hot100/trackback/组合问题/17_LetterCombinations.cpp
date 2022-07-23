//电话号码的组合
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    vector<string> result;
    string s;
    void backtrack(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';        
        string letters = letterMap[digit];      
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);            
            backtrack(digits, index + 1);    
            s.pop_back();                       
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtrack(digits, 0);
        return result;
    }
};