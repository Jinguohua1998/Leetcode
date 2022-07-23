#include <string>
#include <vector>

using namespace std;

// 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
// 有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。


class Solution {
private:
    vector<string> res;
    string str;
    void backtrack(string s, int startIndex, int pointNum){
        if(pointNum == 3){
            if(isValid(s, startIndex, s.size()-1))
                res.push_back(s);
            return;
        }
        for(int i = startIndex; i < s.size(); ++i){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin()+i+1, '.');
                backtrack(s, i+2, pointNum+1);
                s.erase(s.begin()+i+1);
            }else
                break;
        }
    }

    bool isValid(string& s, int start, int end){
    // isValid函数类似 lc 131中的isPalindrome判断是否回文
        if(start > end)
            return false;
        if(s[start] == '0' && start != end){ // 开头为0的不是合法IP
            return false;
        }
        int num = 0;
        for(int i = start; i <= end; ++i){
            if(s[i] > '9' || s[i] < '0')
                return false;
            num = num*10 + (s[i] - '0');
            if(num > 255)
                return false;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12)
            return res;
        backtrack(s, 0, 0);
        return res;
    }
};