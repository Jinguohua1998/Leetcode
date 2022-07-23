#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s;
    getline(cin, s);
 
    char c = tolower(getchar());
 
    int n = 0;
    for (auto i : s) {
        if (tolower(i) == c) {
            ++n;
        }
    }
    cout << n << endl;
}