#include <vector>
#include <algorithm>

using namespace std;

//桶思想
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> vec(26);
        for(auto c : tasks){
            ++vec[c-'A'];
        }
        sort(vec.begin(), vec.end(), [](int& x, int& y){return x > y;});
//cnt:任务数量并列最多的任务有多少个
        int cnt = 1;
        while(cnt < vec.size() && vec[cnt] == vec[0])
            ++cnt;
        return max(len, cnt+(n+1)*(vec[0]-1)); // 相同任务之间间隔为n段，所以要n+1，最后一段不用间隔，所以只要cnt
    }
};