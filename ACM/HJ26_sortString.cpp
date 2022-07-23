#include<bits/stdc++.h>

using namespace std;

int main()
{
    string n;
    while(getline(cin,n))
    {
        vector<char>v;
        for(int i=0;i<=25;i++)
        {
            for(int j=0;j<n.size();j++)
            {
                if(n[j]-'a'==i||n[j]-'A'==i)v.push_back(n[j]);
            }
        }
        for(int i=0,k=0;i<n.size()&&k<v.size();i++)
        {
            if((n[i]>='a'&&n[i]<='z')||(n[i]>='A'&&n[i]<='Z'))
            {n[i]=v[k];k++;}
        }
        cout<<n<<endl;
    }
}