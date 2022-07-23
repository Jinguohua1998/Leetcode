#include<bits/stdc++.h>

using namespace std;

/*
输入
1 2 3
4 5
0 0 0 0 0

输出
6
9
0


*/

int main(){
    int num = 0,sum = 0;
    while(cin>>num){
        sum += num;
        if(cin.get() == '\n'){
            cout<<sum<<endl;
            sum = 0;
        }
    }
     
    return 0;
}