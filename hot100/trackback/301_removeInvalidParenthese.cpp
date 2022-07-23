#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

//回溯法
class Solution {
public:
    unordered_set<string> strSet;         // 需要去重
    vector<string> removeInvalidParentheses(string s) {
// 先计算左右括号分别需要删除的数量
        int l = 0;
        int r = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                ++l;
            }else if(s[i] == ')'){
                if(l == 0)
                    ++r;
                else
                    --l;
            }
        }
        string t;
        backtrack(s, t, 0, l, r, 0, 0);
        vector<string> res(strSet.begin(), strSet.end());
        return res;
    }

    void backtrack(string& s, string&t, int i, int l, int r, int leftCount, int rightCount){ 
    // 这里的参数既要要有要删除的左右括号个数l和r，也要有已有的左右括号个数
        if(i == s.size()){
            if(l == 0 && r == 0){
                strSet.insert(t);
            }
            return;
        }
        // 删除左/右括号
        if(s[i] == '(' && l > 0){
            backtrack(s, t, i+1, l-1, r, leftCount, rightCount);
        }
        if(s[i] == ')' && r > 0){
            backtrack(s, t, i+1, l, r-1, leftCount, rightCount);
        }

        // 加上左/右括号
        t.push_back(s[i]);
        // 既不是左括号也不是右括号
        if(s[i] != '(' && s[i] != ')'){
            backtrack(s, t, i+1, l, r, leftCount, rightCount);
        }else if(s[i] == '('){
            backtrack(s, t, i+1, l, r, leftCount+1, rightCount);
        }else if(rightCount < leftCount){
            backtrack(s, t, i+1, l, r, leftCount, rightCount+1);
        }
        t.pop_back();
        //剪枝操作
    }
};