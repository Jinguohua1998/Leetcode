//拓扑排序
//即判断是不是有向无环图
//分为DFS（访问每个点进行标记）和BFS（每个点入度）
//都需要构造边的邻接矩阵adjacency(也可以叫edges)
#include <vector>
#include <queue>

using namespace std;

//BFS
//队列queue+入度表indegrees
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegrees(numCourses, 0);
        vector<vector<int>> adjacency(numCourses);
        for (const auto& info : prerequisites){
            adjacency[info[1]].push_back(info[0]);
            ++indegrees[info[0]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(indegrees[i] == 0)
                q.push(i);
        }

        int visited = 0;
        while(!q.empty()){
            ++visited;
            int u = q.front();
            q.pop();
            for(int v : adjacency[u]){
                -- indegrees[v];
                if(indegrees[v] == 0)
                    q.push(v);
            }
        }
        return visited == numCourses;
    }
};


//DFS
// flag
// 未被 DFS 访问：i == 0；
// 已被其他节点启动的 DFS 访问：i == -1；
// 已被当前节点启动的 DFS 访问：i == 1。
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacency(numCourses);
        for (const auto& info : prerequisites){
            adjacency[info[1]].push_back(info[0]);
        }
        vector<int> flags(numCourses);
        for(int i = 0; i < numCourses; ++i){
            if(!dfs(adjacency, flags, i))
                return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>>& adjacency, vector<int>& flags, int i){
        if(flags[i] == 1)
            return false;
        if(flags[i] == -1)
            return true;
        flags[i] = 1;
        for(auto j : adjacency[i]){
            if(!dfs(adjacency, flags, j))
                return false;
        }
        flags[i] = -1;
        return true;
    }
};