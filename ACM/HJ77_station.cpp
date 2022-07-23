// 回溯法 + 栈
// 类似于lc 22
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> sche;

void backtrack(const vector<int>& arr, stack<int> station, int inIdx, int outIdx){
    
    // 递归结束条件
    if(inIdx == arr.size() && outIdx == arr.size()){
        res.push_back(sche);
        return;
    }

    // 本层递归树的操作
    // 可以考虑先进站，也可以先出站
    if(inIdx != arr.size()){
        station.push(arr[inIdx]);
        backtrack(arr, station, inIdx+1, outIdx);
        station.pop();
    }
    if(!station.empty()){ // 这里不能用 outIdx != arr.size()
        int x = station.top();
        station.pop();
        sche.push_back(x);
        backtrack(arr, station, inIdx, outIdx+1);
        sche.pop_back();
        station.push(x);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    res.clear();
    sche.clear();
    stack<int> station;
    backtrack(arr, station, 0, 0);
    vector<string> outings;
    for(auto tmp : res){
        string s;
        for(int i = 0; i < tmp.size(); ++i){
            s += to_string(tmp[i]);
            if( i != tmp.size() - 1)
                s += " ";
        }
        outings.push_back(s);
    }
    sort(outings.begin(), outings.end());
    for(auto& outing : outings){
        cout << outing << endl;
    }
}