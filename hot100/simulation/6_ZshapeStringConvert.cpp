#include <string>
#include <vector>

using namespace std;

// 按行排序
// 模拟法
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2)
            return s;
        vector<string> rows(min(numRows, int(s.size())));
        int rowIndex = 0;
        bool goingDown = false;
        for(auto& ch : s){
            rows[rowIndex].push_back(ch);
            if(rowIndex == 0 ||  rowIndex == numRows-1){
                goingDown = !goingDown;
            }
            rowIndex += goingDown ? 1 : -1;
        }
        string res;
        for(string row : rows)
            res += row;
        return res;
    }
};

//按行访问
//行0中的字符位于索引k(2*numRows-2)处
//行numRows-1中的字符位于索引k(2*numRows-2)+numRows-1处
//内部的行i中的字符位于索引k(2*numRows-2)+i以及(k+1)(2*numRows-2)-i
class Solution{
    public:
        string convert(string s, int numRows){

            if(numRows == 1)
                return s;

            string res;

            int n = s.size();
            int cycleLen = 2 * numRows - 2;

            for(int i = 0; i < numRows; ++i){
//分别处理第0行，第1行，第2行...
                for(int j = 0; j + i < n; j += cycleLen){
                    res += s[j+i];
                    if(i != 0 && i != numRows && j + cycleLen - i < n)
                        res += s[j+cycleLen-i];
                }
            }
            return res;
        }
};