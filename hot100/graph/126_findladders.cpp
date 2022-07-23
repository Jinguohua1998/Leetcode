#include <bits/stdc++.h>

using namespace std;

// 单词接龙v2

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> search(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        deque<vector<string>> worker;
        worker.push_back({beginWord});
        while(!worker.empty()){
            unordered_set<string> visited;
            for(int i = worker.size(); i > 0; --i){
                auto sub = worker.front(); worker.pop_front();
                auto tail = sub.back();
                if(tail == endWord){
                    res.push_back(sub);
                    continue;
                }
                for(int j = 0; j < tail.size(); ++j){
                    char temp = tail[j];
                    for(char c = 'a'; c <= 'z'; ++c){
                        if(c == temp) continue;
                        tail[j] = c;
                        if(!search.count(tail)) continue;
                        visited.insert(tail);
                        sub.push_back(tail);
                        worker.push_back(sub);
                        sub.pop_back();
                    }
                    tail[j] = temp;
                }
            }
            if(!res.empty()) return res;
            for(auto& w : visited) search.erase(w);
        }
        return {};
    }
};