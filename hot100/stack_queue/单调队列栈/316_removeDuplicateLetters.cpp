#include <string>
#include <vector>
using namespace std;

//首先考虑一个简单的问题：给定一个字符串 s
//如何去掉其中的一个字符 ch，使得得到的字符串字典序最小呢
//答案是：找出最小的i满足 s[i]>s[i+1] 的下标 i，并去除字符 s[i]


//1. 在考虑字符 s[i]时，如果它已经存在于栈中，则不能加入字符 s[i]。
//为此，需要记录每个字符是否出现在栈中。

//2. 在弹出栈顶字符时，如果字符串在后面的位置上再也没有这一字符，则不能弹出栈顶字符。
//为此，需要记录每个字符的剩余数量，当这个值为 0 时，就不能弹出栈顶字符了。

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> num(26), rec(26);
//num数组为剩余的出现次数
//rec数组记录该数在栈中是否已经出现
        for(auto ch : s)
            ++num[ch-'a'];
        string stk;
        for(auto ch : s){
            if(rec[ch-'a'] == 0){
                while(!stk.empty() && stk.back() > ch){
                    if(num[stk.back() - 'a'] > 0){
                        --rec[stk.back()-'a'];
                        stk.pop_back();
                    }else
                        break;
                }
                stk.push_back(ch);
                ++rec[ch-'a'];
            }
            --num[ch-'a'];            
        }
        return stk;
    }
};

