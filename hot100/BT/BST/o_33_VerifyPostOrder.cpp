#include <vector>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyCore(postorder, 0, postorder.size()-1);
}

bool verifyCore(vector<int>& postorder, int i, int j){
    if(i >= j)
        return true;
//这里用i >= j，考虑到左子树或者右子树为nullptr
    int flag = i;
    while(postorder[flag] < postorder[j])
        ++flag;
    int l = flag-1;
    while(postorder[flag] > postorder[j])
        ++flag;
    return flag == j && verifyCore(postorder, i, l) && verifyCore(postorder, l+1, j-1);
}


};

