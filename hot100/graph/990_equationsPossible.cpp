#include <vector>
#include <string>
#include <numeric>

using namespace std;

//并查集
//判断一对元素是否相连，“动态连通性”问题
//支持“合并”“查询”两种操作
//底层数据结构是数组或者哈希表，表示节点指向的父节点，初始化时指向自己
//合并就是把一个集合的根节点指向另一个集合的根节点，只要根节点一样，就表示在同一个集合中

//应用场景：最小生成树 kruskal算法

//并查集的两种优化方法

//路径压缩
//1. 隔代压缩 
// parent[x] = parent[parent[x]]
//2. 完全压缩（递归）

//按秩合并
//使得高度更低的树的根节点指向高度更高的根节点

class UnionFind{
    private:
        vector<int> parent;

    public:
        UnionFind(){
            parent.resize(26);
            iota(parent.begin(), parent.end(), 0);
        }

//find返回根节点
        int find(int index){
            if(parent[index] == index)
                return index;
            parent[index] = find(parent[index]);
            return parent[index];
//完全压缩路径
        }

        void unite(int index1, int index2){
            parent[find(index1)] = find(index2);
        }
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        for (const string& str: equations) {
            if (str[1] == '=') {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                uf.unite(index1, index2);
            }
        }
        for (const string& str: equations) {
            if (str[1] == '!') {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                if (uf.find(index1) == uf.find(index2)) {
                    return false;
                }
            }
        }
        return true;
    }
};