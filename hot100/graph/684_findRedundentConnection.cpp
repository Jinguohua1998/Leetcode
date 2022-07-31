#include <vector>

using namespace std;

class Solution {
private:
    int n = 1005; // 节点数量3 到 1000
    int father[1005];

    // 并查集初始化
    void init() {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }
    // 并查集里寻根的过程
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // 将v->u 这条边加入并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }
    // 判断 u 和 v是否找到同一个根，本题用不上
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for (int i = 0; i < edges.size(); i++) {
            if (same(edges[i][0], edges[i][1])) return edges[i];
            else join(edges[i][0], edges[i][1]);
        }
        return {};
    }
};


class UnionFind{
public:
    vector<int> parents;
    UnionFind(int n) : parents(n + 1,0){
        for(int i = 0; i <= n; ++i){
            parents[i] = i;
        }
    }
    int find(int u){
        while(parents[u] != parents[parents[u]]){
            parents[u] = parents[parents[u]];
        }
        return parents[u];
    }
    void join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v)  return;
        parents[u] = v;
    }
    bool same(int u, int v){
        return find(u) == find(v);
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for(int i = 0; i < n; ++i){
            if (uf.same(edges[i][0], edges[i][1])) 
                return edges[i];
            else 
                uf.join(edges[i][0], edges[i][1]);
        }
        return {};
    }

};