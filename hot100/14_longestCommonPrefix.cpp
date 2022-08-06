// 编写一个函数来查找字符串数组中的最长公共前缀。

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        string res = strs[0];
        for(int i = 1; i < strs.size(); ++i){
            int j = 0;
            for(; j < res.size() && j < strs[i].size(); ++j){
                if(res[j] != strs[i][j])
                    break;
            }
            res = res.substr(0, j);
            if(res == "")
                return res;
        }
        return res;
    }
};