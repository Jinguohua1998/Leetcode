#include <string>
#include <utility>

using namespace std;


const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};
class Solution {
public:
    string intToRoman(int num) {
        string res;
        for(const auto& itr : valueSymbols){
            while(num > itr.first){
                res += itr.second;
                num -= itr.first;
            }
            if(num == 0)
                break;
        }
        return res;
    }
};