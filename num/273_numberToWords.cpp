#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string res;
        for(int i = 3, unit = 1000000000; i >= 0;--i, unit /= 1000) {
            int curNum = num / unit;
            if(curNum != 0) {
                num -= curNum * unit;
                res = res + toEnglish(curNum) + thousands[i] + " ";
            }
        }
        while(res.back() == ' '){
            res.pop_back();
        }
        return res;
    }

    string toEnglish(int num){
        string curr;
        int hundred = num / 100;
        num %= 100;
        if(hundred != 0){
            curr += singles[hundred] + " Hundred ";
        }
        int ten = num / 10;
        if(ten >= 2){
            curr += tens[ten] + " ";
            num %= 10;
        }
        if(num > 0 && num < 10){
            curr += singles[num] + " ";
        }else if(num >= 10){
            curr += teens[num-10] + " ";
        }
        return curr;
    }
};