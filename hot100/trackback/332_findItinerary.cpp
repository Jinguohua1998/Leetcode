#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

// 涉及到图算法
// 利用map（字典）来实现字典序最小
class Solution {
private:
    unordered_map<string, map<string, int>> targets;
    vector<string> res;
    bool backtrack(int n){
// 注意：这里的backtrack返回bool值，也就是找到字典序最小的立即返回，而不是需要遍历（因为可能有多种方案）
        if(res.size() == n+1)
            return true;
        for(pair<const string, int>& target : targets[res.back()]){
// 这里的pair必须传引用
            if(target.second > 0){
                --target.second;
                res.push_back(target.first);
                if(backtrack(n))
                    return true;
                ++target.second;
                res.pop_back();
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        res.clear();
        targets.clear();
        for(const vector<string>& ticket : tickets){
            ++targets[ticket[0]][ticket[1]];
        }
        int n = tickets.size();
        res.push_back("JFK");
        backtrack(n);
        return res;
    }
};