#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, m;
    cin >> N >> m;
    N /= 10; // 价格是10的整数倍，处理一下降低空间/时间复杂度
    vector<vector<int>> prices(m + 1, vector<int>(3, 0));
    vector<vector<int>> priceMultiplyPriority(m + 1, vector<int>(3, 0));
    // 这里的prices和priceMutiplyPriority相当于0-1背包中的price和value
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a /= 10; 
        b *= a;
        if(c == 0){
            prices[i][0] = a;
            priceMultiplyPriority[i][0] = b;
        }else{
            if(prices[c][1] == 0){
                prices[c][1] = a;
                priceMultiplyPriority[c][1] = b;
            }else{
                prices[c][2] = a;
                priceMultiplyPriority[c][2] = b;
            }
        }
    }
    vector<vector<int>> dp(m+1, vector<int>(N+1, 0));
    for(int i = 1; i <= m; ++i){
        int a = prices[i][0], b = priceMultiplyPriority[i][0];
        int c = prices[i][1], d = priceMultiplyPriority[i][1];
        int e = prices[i][2], f = priceMultiplyPriority[i][2];
        for(int j = 1; j <= N; ++j){
            dp[i][j] = j >= a ? max(dp[i-1][j-a] + b, dp[i-1][j]) : dp[i-1][j];
            dp[i][j] = j >= (a+c) ? max(dp[i-1][j-a-c] + b + d, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= (a+e) ? max(dp[i-1][j-a-e] + b + f, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= (a+c+e) ? max(dp[i-1][j-a-c-e] + b + d + f, dp[i][j]) : dp[i][j];
        }
    }
    cout << dp[m][N]*10 << endl;

}

// 可以用空间复杂度减小的办法