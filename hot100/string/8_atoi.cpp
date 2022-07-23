#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        unsigned long len = s.size();
        int index = 0;
        while(index < len){
            if(s[index] != ' ')
                break;
            ++index;
        }

        if(index == len)
            return 0;

        int sign = 1;
        if(s[index] == '+'){
            ++index;
        }else if(s[index] == '-'){
            ++index;
            sign = -1;
        }

        int res = 0;
        while(index < len){
            if(s[index] < '0' || s[index] > '9')
                break;
            char curChar = s[index];
            if(res > INT_MAX || (res == INT_MAX / 10 && (curChar - '0' > INT_MAX % 10)))
                return INT_MAX;
            if(res < INT_MIN || (res == INT_MIN / 10 && (curChar - '0' > -(INT_MIN % 10))))// INT_MIN%10 要加负号
                return INT_MIN;
            res = res * 10 + sign * (curChar - '0');
            ++index;
        }
        return res;
    }
};