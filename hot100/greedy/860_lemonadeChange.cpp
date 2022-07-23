#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for(auto bill : bills){
            if(bill == 5)
                ++five;
            else if(bill == 10){
                if(five == 0)
                    return false;
                else{
                    --five;
                    ++ten;
                }
            }else{
                if(ten >= 1 && five >= 1){
                    --five;
                    --ten;
                    ++twenty;
                }else if(five >= 3){
                    five -= 3;
                    ++twenty;
                }else
                    return false;
            }
        }
        return true;
    }
};