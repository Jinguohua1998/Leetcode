#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>

using namespace std;

//Unionfind 并查集

class UnionFind{
    private:
        vector<int> parent;
//parent数组维护父亲节点，初始化是父亲节点是自身
        vector<double> weight;
//weight数组维护边的权值, weight的含义是该节点/上一个节点（不是根节点）的比值

    public:
        UnionFind(int n) : parent(n), weight(n, 1.0){
            iota(parent.begin(), parent.end(), 0);
        }

        // 递归法（也可以用迭代法）
        int find(int x){
            if(parent[x] == x)
                return x;
            int origin = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[origin];
            return parent[x];
        }

        double isConnected(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY)
                return -1.0;
            else
                return weight[x]/weight[y];
        }

        void myunion(int x, int y, double value){
            int rootX = find(x), rootY = find(y);
            if(rootX == rootY)
                return;
            parent[rootX] = rootY;
            weight[rootX] = weight[y] * value / weight[x];
        }
};

class Solution{
    public:
        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
            int equationsSize = equations.size();
            UnionFind unionfind(equationsSize*2);
            unordered_map<string, int> strMap;  // 因为表达式是不太规则的，所以要用哈希表
            int id = 0;
            for(int i = 0; i < equationsSize; ++i){
                vector<string> equation = equations[i];
                string var1 = equation[0];
                string var2 = equation[1];
                if(!strMap.count(var1)){
                    strMap[var1] = id;
                    ++id;
                }
                if(!strMap.count(var2)){
                    strMap[var2] = id;
                    ++id;
                }
                unionfind.myunion(strMap[var1], strMap[var2], values[i]);
            }

            int queriesSize = queries.size();
            vector<double> res(queriesSize, -1.0);
            for(int i = 0; i < queriesSize; ++i){
                string var1 = queries[i][0];
                string var2 = queries[i][1];
                int id1, id2;
                if(strMap.count(var1) && strMap.count(var2)){
                    id1 = strMap[var1];
                    id2 = strMap[var2];
                    res[i] = unionfind.isConnected(id1, id2);
                }
            }
            return res;
        }
};