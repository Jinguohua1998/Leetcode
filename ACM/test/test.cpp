#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    istringstream is(s);
    string subStr;
    cout << "dd" << endl;
    int i = 0;
    while(getline(is, subStr, '.')){
        cout << subStr << endl;
        i++;
        cout << i << endl;
    }
}