#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        string res = "0";
        int m = num1.size(), n = num2.size();
        for(int i = n - 1; i >= 0; --i){
            string curr;
            int add = 0;
            for(int j = n -1; j > i; --j)
                curr.push_back(0);
            int y = num2[i] - '0';
            for( int j = m - 1; j >= 0; --j){
                int x = num1[j] - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while( add != 0){
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for(auto& ch : curr)
                ch += '0';
            res = addStrings(res, curr);
        }
        return res;
    }


// 字符串相加的函数
    string addStrings(string& num1, string& num2){
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        // add表示进位
        string res;
        while (i >= 0 || j >= 0 || add != 0){
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int ans = x + y + add;
            res.push_back(ans%10);
            add = ans/10;
            --i;
            --j;
        }
        // reverse的方法类似于lc 67
        reverse(res.begin(), res.end());
        for( auto& ch : res)
            ch += '0';
        return res;
    }
};