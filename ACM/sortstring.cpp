#include<bits/stdc++.h>
using namespace std;

/*

输入

a c bb
f dddd
nowcoder

输出

a bb c
dddd f
nowcoder

*/

int main(){
    vector<string>res;
    string temp;
    while(cin>>temp){
        res.push_back(temp);
        if(cin.get()=='\n'){
            sort(res.begin(),res.end());
            for(int i=0;i<res.size();i++){
                cout<<res[i]<<" ";
            }
            cout<<endl;
            res.clear();
        }
    }
    return 0;
}

 
int main() {
    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        string str;
        vector<string> vec;
        while (getline(ss, str, ' ')) {
            vec.push_back(str);
        }
        sort(vec.begin(),vec.end());
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
    return 0;
}