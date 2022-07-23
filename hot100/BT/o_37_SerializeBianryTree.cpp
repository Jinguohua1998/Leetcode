#include <string>
#include <list>

using namespace std;
// 前序遍历,与第7题“根据前序遍历和中序遍历”类似
// 用vector数据结构会提交超时，最好用list
// 同lc 297
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec{
    public:
    //r是递归"recursive"的意思
        void rserialize(TreeNode* root, string& str){
            if(root == nullptr){
                str += "None,";
            }else{
                str += to_string(root->val) + ",";
                rserialize(root->left, str);
                rserialize(root->right, str);
            }
        }

        string serialize(TreeNode* root){
            string str;
            rserialize(root, str);
            return str;
        }

        // 根据字符串数组构造二叉树
        TreeNode* rdeserialize(list<string>& dataArray){
            if(dataArray.front() == "None"){
                dataArray.erase(dataArray.begin());
                return nullptr;
            }else{
                TreeNode* newNode = new TreeNode(stoi(dataArray.front()));
                dataArray.erase(dataArray.begin());
                newNode->left = rdeserialize(dataArray);
                newNode->right = rdeserialize(dataArray);
                return newNode;
            }
        }

        // 拆解字符串
        TreeNode* deserialize(string data){
            list<string> dataArray;
            string str;
        //这里如果用substr去掉最后的逗号，可能会增加时间和空间复杂度
            for(auto& ch : data){
                if(ch == ','){
                    dataArray.push_back(str);
                    str.clear();
                }else{
                    str.push_back(ch);
                }
            }
            if(!str.empty()){
                dataArray.push_back(str);
                str.clear();
            }
            return rdeserialize(dataArray);
        }
};