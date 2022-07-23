#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 1;
        for(int i = 0; i < n; ++i){
            map<string, int> strMap;
            int maxNum = 0;
            for(int j = i + 1; j < n; ++j){
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                int a = x1 - x2, b = y1 - y2;
                int k = gcd(a, b);
                string key = to_string(a / k) + "_" + to_string(b / k);
                strMap[key]++ ;
                maxNum = max(maxNum, strMap[key]);
            }
            res = max(maxNum + 1, res);
        }
        return res;
    }
};