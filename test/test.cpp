#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


class Solution {
public:
    bool compare(string& s1, string& s2) {
        return s1.substr(0, 2) < s2.substr(0, 2) || 
            (s1.substr(0, 2) == s2.substr(0, 2) && s1.substr(3, 2) < s2.substr(3, 2));
    }

    int minStr(string& s1, string& s2) {
        int res;
        int sec1 = stoi(s1.substr(3, 2)), sec2 = stoi(s2.substr(3, 2));
        int min1 = stoi(s1.substr(0, 2)), min2 = stoi(s2.substr(0, 2));
        int sec;
        int min;
        if (sec1 >= sec2) {
            sec = sec1 - sec2;
            cout << " sec" << sec << endl;
        } else {
            min1 --;
            sec = sec1 + 60 - sec2;
        }
        min = min1 - min2;
        res = sec + min * 60;
        return res;
    }
    
    /* Write Code Here */
    int findMinDifference(vector < string > timePoints) {
        string s1 = timePoints[0], s2 = timePoints[1];
        if(compare(s1, s2)) swap(s1, s2);
        int res = minStr(s1, s2);
        s2[0] += 2;
        s2[1] += 4;
        res = min(res, minStr(s2, s1));
        return res;
    }
};
int main() {
    /*
    int res;

    int timePoints_size = 0;
    cin >> timePoints_size;
    vector<string> timePoints;
    string timePoints_item;
    for(int timePoints_i=0; timePoints_i<timePoints_size; timePoints_i++) {
        getline(cin, timePoints_item);
        timePoints.push_back(timePoints_item);
    }
    Solution *s = new Solution();
    res = s->findMinDifference(timePoints);
    cout << res << endl;
    
    return 0;
    */
    string s1 = "00:00";
    string s2 = "00:10";
    vector<string> timePoints_item;
    timePoints_item.push_back(s1);
    timePoints_item.push_back(s2);
    Solution *s = new Solution();
    cout << s->findMinDifference(timePoints_item) << endl; 

}