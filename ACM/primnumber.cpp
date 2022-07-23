// #include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    long m;
    while(cin>>m)
    {
        for(long i=2;i*i<=m;i++)
        {
            while(m%i==0)
            {
                cout<<i<<" ";
                m/=i;
            }
        }
        if(m>=2) cout<<m<<" ";//如果m=1,则while循环中刚好被质数分解完，如果大于1，说明没有被分解完，m就是那最后一个质数
                              //同时，这句也可以应对输入为质数的特殊情况
        cout<<endl;
    }
}