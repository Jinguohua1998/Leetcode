#include <vector>
#include <unordered_map>

using namespace std;

//哈希表
class Solution1 {
    public:
        char firstUniqChar(string s){
            unordered_map<char, bool> dic;
            for(char ch : s){
                dic[ch] = (dic.find(ch) == dic.end());
            }
            for(char ch : s){
                if(dic[ch])
                    return ch;
            }
            return ' ';
        }
};

//有序哈希表
//多用了一个vector，但是不用二次遍历，节约时间
class Solution2 {
public:
    char firstUniqChar(string s) {
        vector<char> keys;
        unordered_map<char, bool> dic;
        for(char c : s) {
            if(dic.find(c) == dic.end())
                keys.push_back(c);
            dic[c] = dic.find(c) == dic.end();
        }
        for(char c : keys) {
            if(dic[c]) return c;
        }
        return ' ';
    }
};
