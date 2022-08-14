#include <bits/stdc++.h>

using namespace std;

//https://leetcode-cn.com/problems/min-cost-to-connect-all-points/solution/prim-and-kruskal-by-yexiso-c500/

// Prim算法
// 非常类似于Dijkstra算法，贪心算法
/*
抽象（假想:假设存在，但不存在）出两个集合，集合V 和集合Vnew

集合V保存未加入到最小生成树中的节点，最开始，所有的图节点都在集合V中

集合Vnew保存已经加入到最小生成树中的节点，如果一个节点加入到了最小生成树中，则将该节点加入到Vnew
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        return prim(points, 0);
    }

    int prim(vector<vector<int>>& points, int start){
        // 将所有点分为两个集合V和Vnew
        int n = points.size();
        int res = 0;
        vector<vector<int>> graph(n, vector<int>(n));
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int dist =  abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i][j] = dist;
                graph[j][i] = dist;
            }
        }
        // 记录V[i]到Vnew的最近距离
        vector<int> lowcost(n, INT_MAX);
        // 记录V[i]是否加入到了Vnew
        vector<int> v(n, -1);
            
        // 先将start加入到Vnew中
        v[start] = 0;
        for(int i = 0; i < n; ++i){
            if(i == start)
                continue;
            lowcost[i] = graph[i][start];
        }

        for(int i = 1; i < n; ++i){
            int minIdx = -1;
            int minVal = INT_MAX;
            for(int j = 0; j < n; ++j){
                if(v[j] == 0)
                    continue;
                if(lowcost[j] < minVal){
                    minIdx = j;
                    minVal = lowcost[j];
                }
            }

            res += minVal;
            v[minIdx] = 0;
            lowcost[minIdx] = -1;

            for(int j = 0; j < n; ++j){
                if(v[j] == -1 && graph[j][minIdx] < lowcost[j])
                    lowcost[j] = graph[j][minIdx];
            }
        }

        return res;
    }
};

// 还可以用堆优化

class Solution {
public:
    int prim(vector<vector<int> >& points, int start) {
        int n = points.size();
        if (n == 0) return 0;
        int res = 0;

        // 将points转化成邻接表
        vector<vector<int> > g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        
        // 记录V[i]到Vnew的最近距离
        vector<int> lowcost(n, INT_MAX);
        // 记录V[i]是否加入到了Vnew
        vector<int> v(n, -1);

        // 格式：<距离, 下标>
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<int> > pq;
        pq.push(make_pair(0, start));
        
        while (!pq.empty()) {
            auto [dist, i] = pq.top();
            pq.pop();
            if (v[i] == 0) continue;
            v[i] = 0;
            res += dist;

            for (int k = 0; k < g[i].size(); k++) {
                int j = g[i][k];
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);    // 计算曼哈顿距离
                if (v[j] == -1 && lowcost[j] > w) {
                    lowcost[j] = w;
                    pq.push(make_pair(w, j));
                }
            }
        }
        return res;

    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        return prim(points, 0);  
    }
};


// Krustal算法
// 效率远低于prim算法

/*
Prim算法是以顶点为基础（每次寻找离Vnew最近的顶点）；

而Kruskal算法是以 边 为基础，每次从 边 集合中寻找最小的边（不管两个顶点属于V还是Vnew），
然后判断该边的两个顶点是否同源（属于同一个连通分量）。

Kruskal需要对所有的边进行排序，然后从小到大，依次遍历每条边，同时判断每条边是否同源，
如果同源，跳过；如果不同源，将两个连通分量合并，直到所有顶点属于同一个连通分量，算法结束。
*/

class UnionFind{
public:
    vector<int> parents;
    vector<int> len;
    int num; // 边集合的个数，初始化为0
    UnionFind(int n) : parents(n), num(n), len(n, 0){
        for (int i = 0; i < n; ++i){
            parents[i] = i;
        }
        
    }

    int find(int x){
        while(parents[x] != x){
            parents[x] =  parents[parents[x]];
            x = parents[x];
        }
        return x;
    }

    bool isConnected(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        return rootx == rooty;
    }

    int unite(int x, int y, int length){
        --num;
        int rootx = find(x);
        int rooty = find(y);
        parents[rooty] = rootx;
        len[rootx] += length + len[rooty];
        return len[rootx];
    }
};

struct Edge{
    int start;
    int end;
    int len;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res;
        int n = points.size();
        UnionFind uf(n);

        vector<Edge> edges;
        // 建立点-边式数据结构
        for(int i = 0; i < n; ++i){
            for (int j = i+1; j < n; ++j){
                Edge edge{i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])};
                edges.emplace_back(edge);
            }
        }
        sort(edges.begin(), edges.end(),
            [](const auto&a, const auto& b){
                return a.len < b.len;
        });

        for(auto& e : edges){
            if(!uf.isConnected(e.start, e.end)){
                res = uf.unite(e.start, e.end, e.len);
            }
            if(uf.num == 1)
                return res;
        }
        return 0;
    }
};