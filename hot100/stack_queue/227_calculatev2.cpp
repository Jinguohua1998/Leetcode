// 基本计算器v2
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    stack<int> num;  //存贮数字
    stack<char> op;  //存贮操作

    void eval() 
    {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char c = op.top(); op.pop();
        int r;
        if (c == '+') r = a + b;
        else if (c == '-') r = a - b;
        else if (c == '*') r = a * b;
        else r = a / b;
        num.push(r);
    }

    int calculate(string s) {
        s = '0' + s;  // 对开头是负数的处理 
        unordered_map<char, int> pr; 
        pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] = 2; //定义运算符的优先级
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i]; 
            if(c == ' ') continue;  //跳过空格
            if(isdigit(c))     //c是数字,读取一个连续的数字
            {
                int x = 0, j = i;
                while(j < s.size() && isdigit(s[j])) x = x * 10 + (s[j++] - '0');
                num.push(x);    //加入数字栈中
                i = j - 1;        
            }
            else  //c是操作符 
            {     //op栈非空并且栈顶操作符优先级大于等于当前操作符c的优先级，进行eval()计算
                while(op.size() && pr[op.top()] >= pr[c]) eval(); 
                op.push(c);
            }
        }
        while(op.size()) eval(); 
        return num.top();
    }
};