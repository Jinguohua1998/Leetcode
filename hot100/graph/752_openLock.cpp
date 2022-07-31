/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。
*/

#include <bits/stdc++.h>

using namespace std;

//BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }

        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) {
            return -1;
        }

        auto num_prev = [](char x) -> char {
            return (x == '0' ? '9' : x - 1);
        };
        auto num_succ = [](char x) -> char {
            return (x == '9' ? '0' : x + 1);
        };

        // 枚举 status 通过一次旋转得到的数字
        auto get = [&](string& status) -> vector<string> {
            vector<string> ret;
            for (int i = 0; i < 4; ++i) {
                char num = status[i];
                status[i] = num_prev(num);
                ret.push_back(status);
                status[i] = num_succ(num);
                ret.push_back(status);
                status[i] = num;
            }
            return ret;
        };

        queue<pair<string, int>> q;
        q.emplace("0000", 0);
        unordered_set<string> seen = {"0000"};

        while (!q.empty()) {
            auto [status, step] = q.front();
            q.pop();
            for (auto&& next_status: get(status)) {
                if (!seen.count(next_status) && !dead.count(next_status)) {
                    if (next_status == target) {
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1);
                    seen.insert(move(next_status));
                }
            }
        }

        return -1;
    }
};


// 双向BFS
// 使用朴素 BFS 进行求解时，队列中最多会存在“两层”的搜索节点。
// 因此搜索空间的上界取决于 目标节点所在的搜索层次的深度所对应的宽度,可能面临的搜索空间爆炸问题
class Solution {
public:
    string s,t; 
    unordered_set<string> st;
    int openLock(vector<string>& deadends, string target) {
        s = "0000";
        t = target;
        if(s == t) return 0;
        for(const auto& d : deadends) st.insert(d);
        if(st.count(s)) return -1;
        int ans = bfs();
        return ans;
    }
    int bfs(){
        queue<string> d1,d2;
        unordered_map<string,int> m1,m2;
        d1.push(s); m1[s] = 0;
        d2.push(t); m2[t] = 0;
        while(d1.size() and d2.size()){
            int t = -1;
            if(d1.size() <= d2.size()){
                t = update(d1,m1,m2);
            }
            else{
                t = update(d2,m2,m1);
            }
            if(t != -1) return t;
        }
        return -1;
    }
    int update(queue<string>& q,unordered_map<string,int>& cur,unordered_map<string,int>& other){
        int m = q.size();
        while (m-- > 0) {
            string t = q.front(); q.pop();
            int step = cur[t];
            for(int i = 0; i < 4; i++){
                for(int j = -1; j <= 1; j++){
                    if(j == 0) continue;
                    int origin = t[i] - '0';
                    int next = (origin + j) % 10;
                    if(next == -1) next = 9;
                    string copy = t;
                    copy[i] = '0' + next;
                    if(st.count(copy) or cur.count(copy)) continue;
                    if(other.count(copy)) return step + 1 + other[copy];
                    else{
                        q.push(copy);
                        cur[copy] = step + 1;
                    }
                }
            }
        }
        return -1;
    }
};