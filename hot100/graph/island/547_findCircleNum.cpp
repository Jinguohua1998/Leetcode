#include <bits/stdc++.h>

using namespace std;

// 并查集 union-find
class UnionFind{
public:
    int find(int x){
        while(father[x] != x){
            father[x] = father[father[x]];
            x = father[x];
        }
        return x;
    }
    
    bool is_connected(int x,int y){
        return find(x) == find(y);
    }
    
    void unite(int x,int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            father[rootx] = rooty;
            num_of_sets--;
        }
    }
    int get_num_of_sets(){
        return num_of_sets;
    }
    UnionFind(int n) : father(n), num_of_sets(n){
        for(int i =0; i < n; ++i)
            father[i] = i;
    }
    
private:
    vector<int> father;
    int num_of_sets = 0;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf(isConnected.size());
        for(int i = 0;i < isConnected.size();i++){
            for(int j = 0;j < i;j++){
                if(isConnected[i][j]){
                    uf.unite(i,j);
                }
            }
        }
        return uf.get_num_of_sets();
    }
};