#include <bits/stdc++.h>

using namespace std;

// BFS

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> indegrees(numCourses);
        vector<vector<int>> adjacency(numCourses);
        for(const auto& info : prerequisites){
            adjacency[info[1]].push_back(info[0]);
            ++indegrees[info[0]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(indegrees[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            res.push_back(u);
            q.pop();
            for(int v : adjacency[u]){
                --indegrees[v];
                if(indegrees[v] == 0)
                    q.push(v);
            }
        }
        if(res.size() == numCourses)
            return res;
        return {};
    }
};