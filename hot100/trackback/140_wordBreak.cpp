#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> path;
    unordered_set<string> strMap;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        strMap = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return res;
    }
    void backtrack(string& s, int index){
        int n = s.size();
        if(index == n){
            string tmp = path[0];
            for(int i = 1; i < path.size(); ++i){
                tmp += " " + path[i];
            }
            res.push_back(tmp);
            return;
        }
        for(int i = index; i < n; ++i){
            string str = s.substr(index, i - index + 1);
            if(strMap.count(str)){
                // res.push_back(str);
                path.push_back(str);
                backtrack(s, i + 1);
                path.pop_back();
            }
        }
    }
};