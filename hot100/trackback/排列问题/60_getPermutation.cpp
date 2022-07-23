#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        visited.resize(n);
        int order = 0;
        backtrack(n, k, 0, order);
        return res;
    }
private:
    vector<int> visited;
    string res;
    bool backtrack(int n, int k, int index, int& order){
        if(index == n){
            ++order;
            if(order == k)
                return true;
            else
                return false;
        }else{
            for(int i = 0; i < n; ++i){
                if(visited[i])
                    continue;
                else{
                    visited[i] = 1;
                    res.push_back('0'+i);
                    if(!backtrack(n,k, index+1, order)){
                        visited[i] = 0;
                        res.pop_back();
                    }
                    return true;
                }
            }
        }
        return false;
    }
};

//一种效率更高的回溯方法，见lc46
class Solution{
private:
    vector<int> visited;
    vector<int> factorial;

public:
    string getPermutation(int n, int k){
        visited.resize(n, 0);
        factorial.resize(n);
        
    }
};


//数学的方法
class Solution{
    public:
        string getPermutation(int n, int k){
            int factorial[n];
            factorial[0] = 1;
            for(int i = 1; i < n; ++i)
                factorial[i] = factorial[i-1] * i;
            --k;
            string res;
            vector<int> visited(n+1, 0);
            for(int i = 1; i <= n; ++i){
                int order = k / factorial[n-i];
                for(int j = 1; j <= n; ++j){
                    if(order == 0 && visited[j] == 0){
                        res.push_back(j+'0');
                        visited[j] = 1;
                        break;
                    }
                    if(visited[j] == 0)
                        --order;
                }
                k %= factorial[n-i];
            }
            return res;
        }
};