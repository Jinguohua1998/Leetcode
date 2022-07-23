#include <bits/stdc++.h>

using namespace std;

// Dijkastra算法（贪心算法）
/*
每次从「未确定节点」中取一个与起点距离最短的点，将它归类为「已确定节点」，
并用它「更新」从起点到其他所有「未确定节点」的距离。直到所有点都被归类为「已确定节点」。
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (auto &t : times) {          
            g[t[0]-1][t[1]-1] = t[2];
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        vector<bool> used(n, false);
        for (int i = 0; i < n; ++i) {
            int x = -1;
            for (int y = 0; y < n; ++y) {
                if (!used[y] && (x == -1 || dist[y] < dist[x])) {
                    x = y;
                }
            }
            used[x] = true;
            for (int y = 0; y < n; ++y) {
                dist[y] = min(dist[y], dist[x] + g[x][y]);
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};


// 用优先队列优化的dijkstra算法

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<pair<int, int>>> g(n);
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]);
        }
        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k - 1);
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if (dist[x] < time) {
                continue;
            }
            for (auto &e : g[x]) {
                int y = e.first, d = dist[x] + e.second;
                if (d < dist[y]) {
                    dist[y] = d;
                    q.emplace(d, y);
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};

// floyd算法（动态规划）
// d[i][j] = min(d[i][j],d[i][k]+d[k][j])
class Solution {
public:  
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2));
        for (auto& it : times)          
            dp[it[0]][it[1]] = it[2];
        for (int i = 1; i <= n; i++)    
            dp[i][i] = 0;//自己到自己为0
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] );
                }
            }
        }
        int ret = 0;
        for (int i = 1; i <= n; i++)    
            ret = max(ret, dp[k][i]);
        return ret == INT_MAX / 2 ? -1 : ret;
    }
};

