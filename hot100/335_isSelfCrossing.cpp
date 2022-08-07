/*
给你一个整数数组 distance 。

从 X-Y 平面上的点 (0,0) 开始，先向北移动 distance[0] 米，然后向西移动 distance[1] 米，
向南移动 distance[2] 米，向东移动 distance[3] 米，持续移动。也就是说，每次移动后你的方位会发生逆时针变化。

判断你所经过的路径是否相交。如果相交，返回 true ；否则，返回 false 。
*/

#include <bits/stdc++.h>

using namespace std;

// 归纳法
class Solution {
public:
    bool isSelfCrossing(vector<int>& d) {
        int n = d.size();
        if(n < 4)   return false;
        for(int i = 3; i < n; ++i){
            if(d[i] >= d[i - 2] && d[i - 1] <= d[i - 3])    return true;
            if(i >= 4 && d[i - 1] == d[i - 3] && d[i] + d[i - 4] >= d[i - 2])   return true;
            if(i >= 5 && d[i - 1] <= d[i - 3] && d[i - 2] > d[i - 4] && d[i] + d[i - 4] >= d[i - 2] && d[i - 1] + d[i - 5] >= d[i - 3]) return true;
        }
        return false;
    }
};


/*
归纳法（归纳路径不交叉时的状态）
思路和算法

根据归纳结果，我们发现当不出现路径交叉时，只可能有以下三种情况：

第 1 种情况：对于每一次移动 i，第 i 次移动距离都比第 i-2 次移动距离更长，
第 2 种情况：对于每一次移动 i，第 i 次移动距离都比第 i-2 次移动距离更短，
第 3 种情况：对于每一次移动 i < j，都满足第 1 种情况；对于每一次移动 i > j，都满足第 2种情况。


*/ 
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();

        // 处理第 1 种情况
        int i = 0;
        while (i < n && (i < 2 || distance[i] > distance[i - 2])) {
            ++i;
        }

        if (i == n) {
            return false;
        }

        // 处理第 j 次移动的情况
        if ((i == 3 && distance[i] == distance[i - 2])
            || (i >= 4 && distance[i] >= distance[i - 2] - distance[i - 4])) {
            distance[i - 1] -= distance[i - 3];
        }
        ++i;

        // 处理第 2 种情况
        while (i < n && distance[i] < distance[i - 2]) {
            ++i;
        }

        return i != n;
    }
};