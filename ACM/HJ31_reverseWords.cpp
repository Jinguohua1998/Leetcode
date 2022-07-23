#include <bits/stdc++.h>

using namespace std;

int main()
{
    string In ;//= "$bo*y gi!r#l";
    getline(cin, In);
    vector<string> Ou;
    In.push_back(' ');
    int S = 0, E = 0, L = In.length();
    //要注意开头并不是合法字符
    for (int i = 0; i < L; i++)
    {
        if ((islower(In[i]) || isupper(In[i]))) // toupper，tolower表示字符转换
        {
            S = i;
            break;
        }
    }
    for (int i = S; i < L; i++)
    {
        if (!(islower(In[i]) || isupper(In[i])))
        {
            E = i;
            string tem = In.substr(S, E - S);
            Ou.push_back(tem);
            S = i + 1;
        }
    }
    for (int i = Ou.size() - 1; i > -1; i--)
    {
        cout << Ou[i] << ' ';
    }
    return 0;
}