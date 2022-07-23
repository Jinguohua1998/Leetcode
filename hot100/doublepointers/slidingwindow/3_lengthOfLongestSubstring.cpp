#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 同offer 48

//滑动窗口（以第i个元素为首位的最长不重复的字符串长度）
int lengthOfLongestSubString(string s){
    unordered_set<char> occ;
    int n = s.size();
    int rk = 0, ans = 0;
    // 滑动窗口的统一格式 ： 以滑动窗口的左端点为循环变量
    for(int i = 0; i < n; ++i){
        if(i != 0)
            occ.erase(s[i-1]);
            // 注意 ： 这里是i-1
        while(rk < n && !occ.count(s[rk])){
            occ.insert(s[rk]);
            ++rk;
        }
        ans = max(ans, rk - i);
    }
    return ans;
}

// 这个解法有问题，因为字符不止是小写字母，有可能是空格或者其他，所以最好不用vector做哈希表
class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        int tmp = 0;
        int res = 0;
        if(s.length() < 2)
            return s.length();
//自己写的哈希表
        vector<int> charmap(26, -1);
        for(int i = 0; i < s.length(); ++i){
            int position = charmap[s[i] - 'a'];
            if(position < 0 || i - position > tmp)
                ++tmp;
            else
                tmp = i - position;
            charmap[s[i] - 'a'] = i;
            res = res > tmp ? res : tmp;
        }
        return res;
    }   
};

int main(){
    string s = "ee";
    cout << s.length();
}