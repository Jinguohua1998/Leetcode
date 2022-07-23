#include<iostream>
#include<vector>
#include<string>

using namespace std;
 
int main(){
    string s;
     
    while(getline(cin,s)){
        vector<string> ans;
        int flag=0; // 判断是不是已经有前面的"
        string temp;
        for(int i=0;i<s.size();i++){
            if(flag){
                if(s[i]!='\"'){
                    temp+=s[i];
                }
                else flag=0;
            }
            else{
                if(s[i]==' '){
                    ans.push_back(temp);
                    temp="";
                }
                else if(s[i]=='\"'){
                    flag=1;
                }
                else{
                    temp+=s[i];
                }
            }
        }
        ans.push_back(temp);
        cout<<ans.size()<<endl;
        for(auto a:ans) cout<<a<<endl;
    }
}