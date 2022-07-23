#include<bits/stdc++.h>

using namespace std;

bool isValidNum(string s){
    // 最好还要判断一下正负号，以及是否有其他字符
    if(s.empty())
        return false;
    if(s[0] == '0' && s.size() > 0) // 不能含有前导零
        return false;
    if(stoi(s) < 0 || stoi(s) > 255)
        return false;
    return true;
}


bool judge_ip(string ip){
    int j = 0;
    istringstream iss(ip);
    string seg;
    while(getline(iss,seg,'.'))
        if(++j > 4 || !isValidNum(seg))
            return false;
    return j == 4;
}


int main(){
    string s;
    while(cin >> s){
        if(judge_ip(s))
            cout << "YES"<< endl;
        else
            cout << "NO" << endl;
    }
}