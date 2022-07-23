//类似题 lc5
#include <string>
#include <vector>

using namespace std;

//动态规划
//一定要从下到上，从左到右遍历，这样保证dp[i + 1][j - 1]都是经过计算的
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    ++result;
                    dp[i][j] = true;
                }
            }
        }
        return result;
    }
};

//中心拓展法
//双指针法
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;
        for(int i = 0; i < 2 * n -1; ++i){
//当i为偶数时，中心为1个数；i为奇数时，中心为两个数
            int left = i/2, right = i/2 + i%2;
            while (left >= 0 && right < n && s[left] == s[right]){
                --left;
                ++right;
                ++res;
            }
        }
        return res;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += extend(s, i, i, s.size()); // 以i为中心
            result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
        }
        return result;
    }
    int extend(const string& s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
};