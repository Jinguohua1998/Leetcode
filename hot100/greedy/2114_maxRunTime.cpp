#include <bits/stdc++.h>

using namespace std;


// 贪心算法
class Solution {
public:
    long long maxRunTime(int n, vector<int> &batteries) {
        sort(batteries.begin(), batteries.end());
        long sum = accumulate(batteries.begin(), batteries.end(), 0L);
        for (int i = batteries.size() - 1;; --i) {
            if (batteries[i] <= sum / n) {
                return sum / n;
            }
            sum -= batteries[i];
            --n;
        }
    }
};

// 二分法


using ll = long long;
ll a[10];
bool ck(ll x)
{
    ll s=0;
    for(int i=1;i<=5;i++)
        if(a[i]<x)
            s+=x-a[i];
    if(s>x)
        return 0;
    return 1;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        for(int i=1;i<=5;i++)
            cin >> a[i];
        ll l=1,r=1.3e9;
        while(l<r)
        {
            ll mid=(l+r+1)>>1;
            if(ck(mid))
                l=mid;
            else
                r=mid-1;
        }
        cout << l << endl;
    }
}