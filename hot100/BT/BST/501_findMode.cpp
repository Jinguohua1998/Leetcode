//要返回出现次数最大的众数

#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 记录上一个节点pre的方法类似于lc 98 lc 530
class Solution {
private:
    int count ;
    int maxCount;
    TreeNode* pre;
    vector<int> res;
    void searchBST(TreeNode* cur){
        if(cur == nullptr)
            return;

        searchBST(cur->left);

        if(pre == nullptr || pre->val != cur->val){
            count = 1;
        }else if(pre->val == cur->val){
            ++count;
        }
        if(count == maxCount)
            res.push_back(cur->val);
        else if(count > maxCount){
            res.clear();
            res.push_back(cur->val);
            maxCount = count;
        }
        pre = cur;

        searchBST(cur->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        TreeNode* pre = nullptr;
        res.clear();
        searchBST(root);
        return res;
    }
};