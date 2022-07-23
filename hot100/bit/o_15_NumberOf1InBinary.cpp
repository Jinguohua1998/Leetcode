//位运算 & | ^
#include <iostream>

using namespace std;

int Numberof1v1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag){
        if(flag & n)
            ++count;
        flag = flag << 1;
    }
    return count;
}

int Numberofv2(int n){
    int count = 0;
    while(n){
        n = n&(n-1);
        ++count;
    }
    return count;
}