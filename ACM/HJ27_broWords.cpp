#include <bits/stdc++.h>

using namespace std;
 
bool is_brothers(string target,string candidate){
    sort(target.begin(),target.end());
    sort(candidate.begin(),candidate.end());
     
    return target==candidate;
}
 
int main(){
    int n;
    while(cin>>n){
        int i,k=0;
        vector<string> v(n);
        for(i=0;i<n;i++){
            cin>>v[i];
        }
         
        int ID;
        string target;
        cin>>target>>ID;
         
        sort(v.begin(),v.end());
         
        string brother;
        for(i=0;i<n;i++){
            if(v[i]!=target){
                if(is_brothers(target,v[i])){
                    if(++k==ID)
                        brother=v[i];
                }
            }
        }
        cout<<k<<endl;
        if(k>=ID)
            cout<<brother<<endl;
    }
     
    return 0;
}