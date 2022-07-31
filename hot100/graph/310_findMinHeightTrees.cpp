#include <bits/stdc++.h>

using namespace std;

/*
我们从边缘开始，先找到所有出度为1的节点，然后把所有出度为1的节点进队列，然后不断地bfs，
最后找到的就是两边同时向中间靠近的节点，那么这个中间节点就相当于把整个距离二分了，
那么它当然就是到两边距离最小的点啦，也就是到其他叶子节点最近的节点了。
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        vector<int> res;
        vector<int> degrees(n);
        vector<vector<int>> edgeMap(n);
        for(auto edge : edges){
            ++degrees[edge[0]];
            ++degrees[edge[1]];
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }
        queue<int> nodeQ;
        for(int i = 0; i < n; ++i){
            if(degrees[i] == 1)
                nodeQ.push(i);
        }
        while(!nodeQ.empty()){
            res.clear();
            int size = nodeQ.size();
            for(int i = 0; i < size; ++i){
                int node = nodeQ.front();
                nodeQ.pop();
                res.push_back(node);
                for(int endNode : edgeMap[node]){
                    --degrees[endNode];
                    if(degrees[endNode] == 1)
                        nodeQ.push(endNode);
                }
            }
        }
        return res;
    }
};