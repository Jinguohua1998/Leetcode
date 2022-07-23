// 栈
#include <iostream>
#include <stack>

using namespace std;

string mp = "+-*/)]}";

bool cmp(char c1, char c2){
    if(c1 == '('){
        return false;
    }else if((c1 == '+' || c1 == '-') && (c2 == '*' || c2 == '/')){
        return false;
    }
    return true;
}

void doCal(stack<double>& stk, stack<char>& so){
    double b = stk.top();
    stk.pop();
    double a = stk.top();
    stk.pop();
    char op = so.top();
    so.pop();
    if(op == '+') 
        a = a+b;
    else if(op == '-') 
        a = a-b;
    else if(op == '*') 
        a = a*b;
    else if(op == '/') 
        a = a/b;
    stk.push(a);
    return ;
}

int main(){
    string s;
    while(getline(cin, s)){
        stack<double> stk;
        stack<char> so; //运算符的栈
        so.push('(');
        s += ')'; // 在等式前后加上左右括号是为了最后一步算完表达式
        bool nextIsOp = false;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
                so.push('(');
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                while(so.top() != '(')
                    doCal(stk, so);
                so.pop();
            }else if(nextIsOp){
                while(cmp(so.top(), s[i]))
                    doCal(stk, so);
                so.push(s[i]);
                nextIsOp = false;
            }else{
                int j = i;
                if(s[j] == '-' || s[j] == '+') //考虑正负数的符号
                    ++i;
                while(mp.find(s[i]) == mp.npos)
                    ++i;
                string t = s.substr(j, i-j);
                stk.push((double)stoi(t));
                --i;
                nextIsOp = true;
            }
        }
        cout << stk.top() << endl;
    }
    return 0;
}