#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

//排序后哈希
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& str : strs){
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }

        vector<vector<string>> res;
        for(auto& element : mp)
            res.push_back(element.second);
        return res;
    }
};


//取代之前的排序操作
class Solution{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs){
            auto arrayHash = [fn = hash<int> {}](const array<int, 26>& arr) -> size_t{
                return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num){
                    return (acc << 1) ^ fn(num);
                });
            };

            unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
            for(string& str : strs){
                array<int, 26> counts{};
                for(auto ch : str)
                    ++counts[ch - 'a'];
                mp[counts].push_back(str);
            }

            vector<vector<string>> res;
            for(auto& element : mp)
                res.push_back(element.second);
            return res;
        }
};