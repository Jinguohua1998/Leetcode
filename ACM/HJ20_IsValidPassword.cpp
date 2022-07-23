#include<bits/stdc++.h>

using namespace std;

// 用双指针法判断是否有重复字符串
int main()
{
    string s;
    while(cin>>s)
    {
        if(s.size()<=8)
        {
            cout<<"NG"<<endl;
        }
        else
        {
            int bw=0,sw=0,num=0,oth=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]>='A' && s[i]<='Z') bw = 1;
                else if(s[i]>='a' && s[i]<='z') sw = 1;
                else if(s[i]>='0' && s[i]<='9') num = 1;
                else oth = 1;
            }
            if(bw+sw+num+oth<3)
            {
                cout<<"NG"<<endl;
                continue;
            }
            else
            {
            // 双指针法
                int count = 0;
                for(int i=0;i<=s.size()-6;i++)
                {
                    for(int j=i+3;j<s.size();j++)
                    {
                        if(s[i]==s[j] && s[i+1]==s[j+1] && s[i+2]==s[j+2])
                        {
                            cout<<"NG"<<endl;
                            count = 1;
                            break;
                        }
                    }
                    if(count == 1) 
                        break;
                }
                if(count==1) 
                    continue;
                cout<<"OK"<<endl;
            }
        }
    }
    return 0;
}

// 用哈希表判断是否有重复字符串
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        if(s.size()<=8)
        {
            cout<<"NG"<<endl;
        }else{
            int bw=0,sw=0,num=0,oth=0;
            for(int i=0;i<s.size();i++){
                if(s[i]>='A' && s[i]<='Z') bw = 1;
                else if(s[i]>='a' && s[i]<='z') sw = 1;
                else if(s[i]>='0' && s[i]<='9') num = 1;
                else oth = 1;
            }
            if(bw+sw+num+oth<3){
                cout<<"NG"<<endl;
                continue;
            }else{
            // 双指针法
                bool isValid = true;
                unordered_map<string, int> strMap;
                for(int i=0;i<=s.size()-3;i++){
                    string subStr = s.substr(i, 3);
                    if(strMap.find(subStr) == strMap.end()){
                        strMap[subStr] = i;
                    }else{
                        if(i - strMap[subStr] >= 3){
                            cout<<"NG"<<endl;
                            isValid = false;
                            break;
                        }
                    }
                }
                if(isValid == true)
                    cout<<"OK"<<endl;
            }
        }
    }
    return 0;
}