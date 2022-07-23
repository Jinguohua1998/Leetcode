#include <bits/stdc++.h>

using namespace std;
 
string get_name(string s)
{
    //这一步也可以自己写循环
    s = s.substr(s.rfind('\\')+1); // 对于'\'要加转义符变成'\\'
    
    if(s.size()>16)
    {
        s = s.substr(s.size()-16);
    }
    return s;
}
int main()
{
    string s;
    vector<string> res;
    unordered_map<string, int> rec;
    int num;
     
    while(cin>>s>>num)
    {
        string ss = get_name(s)+' '+to_string(num);
        if(rec.count(ss)==0)
        {
            rec[ss]=1;
            res.push_back(ss);
        }
        else
            rec[ss]++;
    }

    int i = (res.size()>8)?(res.size()-8):0;
    
    for(; i<res.size(); i++)
    {
        cout<<res[i]<<" "<<rec[res[i]]<<endl;
    }
}