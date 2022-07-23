// 基本计算器v1 （有括号）

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void calc(stack<int>& nums, stack<char>& ops){
        if(nums.size() < 2 || ops.empty())
            return;
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        nums.push(op == '+' ? a + b : a - b);
    }
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        nums.push(0);
        int n = s.size();
        for(int i = 0; i < n; ++i){
            char c = s[i];
            if(c == ' ')
                continue;
            else if(c == '(')
                ops.push(c);
            else if(c == ')'){
                while(!ops.empty()){
                    char op = ops.top();
                    if(op != '(')
                        calc(nums, ops);
                    else{
                        ops.pop();
                        break;
                    }
                }
            }else if(isdigit(c)){
                int cur = c - '0';
                while(i < n - 1 && isdigit(s[i+1])){
                    ++i;
                    cur = cur * 10 + (s[i] - '0');
                }
                nums.push(cur);
            }else{
                if(i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-'))
                    nums.push(0);
                while(!ops.empty() && ops.top() != '(')
                    calc(nums, ops);
                ops.push(c);
            }
        }
        while(!ops.empty())
            calc(nums, ops);
        return nums.top();
    }
};

// 考虑有正负数的情况，如+3 * -8
class Solution {
public:
    unordered_map<char, int> opsPiority;    
    int calculate(string s) {
        opsPiority['-'] = 1;
        opsPiority['+'] = 1;
        opsPiority['*'] = 2;
        opsPiority['/'] = 2;
        opsPiority['%'] = 2;
        opsPiority['^'] = 3;
        // 存放所有的数字
        stack<int> nums;
        // 为了防止第一个数为负数，先往 nums 加个 0
        nums.push(0);
        // 存放所有的操作，包括 +/-
        stack<char> ops;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(c == ' ')
                continue;
            else if(c == '(')
                ops.push(c);
            else if(c == ')') {
                // 计算到最近一个左括号为止
                while(!ops.empty()) {
                    char op = ops.top();
                    if(op != '(')
                        calc(nums, ops);
                    else {
                        ops.pop();
                        break;
                    }
                }
            }
            else {
                if(isdigit(c)) {
                    int cur_num = 0;
                    int j = i;
                    // 将从 i 位置开始后面的连续数字整体取出，加入 nums
                    while(j <n && isdigit(s[j]))
                        cur_num = cur_num*10 + (s[j++] - '0');
                    // 注意上面的计算一定要有括号，否则有可能会溢出
                    nums.push(cur_num);
                    i = j-1;
                }
                else {
                    if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
                        nums.push(0);
                    }
                    // 有一个新操作要入栈时，先把栈内可以算的都算了
                    while(!ops.empty() && ops.top() != '('){
                        char pre = ops.top();
                        if(opsPiority[pre] >= opsPiority[c])
                            calc(nums, ops);
                        else
                            break;
                    }
                    ops.push(c);
                }
            }
        }
        while(!ops.empty())
            calc(nums, ops);
        return nums.top();
    }
    void calc(stack<int> &nums, stack<char> &ops) {
        if(nums.size() < 2 || ops.empty())
            return;
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        int ans = 0;
        if (op == '+') {
            ans = a + b;
        } else if (op == '-') {
            ans = a - b;
        } else if (op == '*') {
            ans = a * b;
        } else if (op == '/') {
            ans = a / b;
        } else if (op == '^') {
            ans = (int)pow(a, b);
        } else if (op == '%') {
            ans = a % b;
        }
        nums.push(ans);
    }
};
