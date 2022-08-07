#include <bits/stdc++.h>

using namespace std;

// 计算质数的个数，0不是质数
// 埃氏筛
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, 1);
        int res = 0;
        for(int i = 2; i < n; ++i){
            if(isPrime[i]){
                ++res;
                if( (long long)i * i < n){
                    for(int j = i * i; j < n; j += i)
                        isPrime[j] = 0;
                }
            }
        }
        return res;
    }
};
