#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//递归法
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return buildTree(nums, 0, n-1);
    }

    TreeNode* buildTree(vector<int>& nums, int start, int end){
        if(start > end)
            return nullptr;
        int mid = start + end >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, start, mid-1);
        node->right = buildTree(nums, mid+1, end);
        return node;
    }
};

//迭代法