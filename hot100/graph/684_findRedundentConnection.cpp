#include <vector>

using namespace std;

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