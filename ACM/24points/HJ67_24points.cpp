#include<bits/stdc++.h>

using namespace std;

vector<double> nums; // 注意 : 这里不能是int
vector<bool> visited;

bool backtrack(int step, double sum){
    if(step == 4)
        return sum == 24 ? true : false;
    else{
        for(int i = 0; i < 4; ++i){
            if(visited[i] == false){
                visited[i] = true;
                if(backtrack(step+1, sum + nums[i]))
                    return true;
                else if(backtrack(step+1, sum - nums[i]))
                    return true;
                else if(backtrack(step+1, sum * nums[i]))
                    return true;
                else if(backtrack(step+1, sum / nums[i]))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
}

int main(){
    nums.resize(4);
    visited.resize(4, false);
    cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
    if(backtrack(0, 0.0))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}