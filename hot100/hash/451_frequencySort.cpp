#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
        string frequencySort(string s) {
            unordered_map<char, int> umap;
            int length = s.size();
            for(auto ch : s){
                ++umap[ch];
            }
            vector<pair<char, int>> vec;
            for(auto& itr : umap)
                vec.push_back(itr);
            sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b){
                return a.second > b.second;
            });
            string res;
            for(auto& element : vec){
                for(int i = 0; i < element.second; ++i)
                    res.push_back(element.first);
            }
            return res;
        }
};