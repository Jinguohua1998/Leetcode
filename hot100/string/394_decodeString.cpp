#include <string>
#include <stack>

using namespace std;

// 用辅助栈
class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<int> nums;
// 记录数字
        stack<string> strs;
// 记录数字前的字符串
        int num;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            if(s[i] <= '9' && s[i] >='0')
                num = num*10 + s[i] - '0';
            else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                res += s[i];
            // 遇到'['则将左边的数字以及字符串压栈
            else if(s[i] == '['){
                strs.push(res);
                nums.push(num);
                num = 0;
                res.clear();
            }
            else{ // 遇到']'则先弹出num，将子串重复num次，再弹出前面的子串并拼接上
                int times = nums.top();
                nums.pop();
                for(int j = 0; j < times; ++j)
                    strs.top() += res;
                res = strs.top();
                strs.pop();
            }
        }
        return res;
    }
};


//递归法
//将 [ 和 ] 分别作为递归的开启与终止条件
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return getString(s, i);
    }

    string getString(string s, int& i){
        if(i == s.size() )
            return "";
        if(s[i] == ']'){
            ++i;
            return "";
        }
        string res;
        int num = 0;
        while((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            res += s[i];
            ++i;
        }
        while(s[i] <= '9' && s[i] >= '0'){
            num = num*10 + s[i] - '0';
            ++i;
        }
        if(num != 0){
            string str = getString(s, i);
            while(num --)
                res += str;
        }
        if(s[i] == '['){
            ++i;
        }
        return res + getString(s, i);

    }
};