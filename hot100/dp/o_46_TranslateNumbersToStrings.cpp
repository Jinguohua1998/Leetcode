#include <string>

using namespace std;

//动态规划，最初的版本需要O（n）大小的数组保存中间结果，这里用常数大小的数字表示（滚动数组法）

class Solution1{
    public:
        int translateNum(int num){
            string s = to_string(num);
            int a = 1, b = 1;
//a:dp[i]   b:dp[i-1]
            for(int i = 1; i < s.length(); ++i){
                string tmp = s.substr(i-1, 2);
                int c = tmp >= "10" && tmp <= "25" ? a + b : a;
                b = a; 
                a = c;
            }
            return a;
        }
};