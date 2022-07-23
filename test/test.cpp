#include <bits/stdc++.h>


using namespace std;

void func1(int&& i){
    i = 1000;
    cout << 2 << endl;
}

forward_list<int> ilist;

int main(){
    vector<int> vec {1,2,3,4};
    auto itr = vec.begin() + 100;
    cout << *itr;

}
