/*
累加数 是一个字符串，组成它的数字可以形成累加序列。

一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，序列中的每个后续数字必须是它之前两个数字之和。

输入："112358"
输出：true 
解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

*/
#include <bits/stdc++.h>

using namespace std;

// 回溯法，空间复杂度较高，也比较耗时
class Solution {
public:
    string num;
    int n;
    vector<vector<int>> list;
    bool isAdditiveNumber(string _num) {
        num = _num;
        n = _num.size();
        return dfs(0);
    }
    bool dfs(int u){
        int m = list.size();
        if(u == n) return m >= 3; //至少包含3个数
        int max = num[u] == '0' ? u + 1 : n; //处理前导0
        vector<int> cur;
        for(int i = u; i < max; i++){ //枚举[u,n - 1]
            cur.insert(cur.begin() , num[i] - '0');
            if(m < 2 or check(list[m - 2], list[m - 1],cur)){
                list.push_back(cur);
                if(dfs(i + 1)) return true;
                list.pop_back();
            }
        }
        return false;
    }
    bool check(vector<int>& a, vector<int>& b, vector<int>& c){
        vector<int> ans;
        int t = 0;
        for(int i = 0; i < a.size() or i < b.size(); i++){
            if(i < a.size()) t += a[i];
            if(i < b.size()) t += b[i];
            ans.push_back(t % 10);
            t /= 10;
        }
        if(t) ans.push_back(1); //处理最高位的进位
        bool ok = (c.size() == ans.size()); //检查长度
        for(int i = 0; i < c.size() and ok; i++){
            if(c[i] != ans[i]) ok = false; //逐位检查
        }
        return ok; 
    }
};



class Solution {
public:
    // 大数加法模板
    string add(string& a,string& b){
        int n1 = a.size()-1;
        int n2 = b.size()-1;
        int carry = 0;
        string ans;

        while(n1>=0||n2>=0||carry>0){
            int t1=n1>=0?a[n1--]-'0':0;
            int t2=n2>=0?b[n2--]-'0':0;
            ans+=(t1+t2+carry)%10+'0';
            carry=(t1+t2+carry)/10;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }

    // num1: [i, j) + num2: [j, k) = sum: [k, ..)
    bool valid(string& num, int i, int j, int k) {
        if (num[i] == '0' && j != i+1) return false;
        if (num[j] == '0' && k != j+1) return false;

        string a = num.substr(i, j-i);
        string b = num.substr(j, k-j);

        string sum = add(a, b);
        if (sum.size() + k > num.size()) return false;

        for (int s = 0; s <= sum.size() - 1; s++) {
            if (sum[s] != num[s+k]) return false;
        }
        if (sum.size() + k == num.size()) return true;

        return valid(num, j, k, sum.size()+k);
    }

    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.size(); i++) {
            for (int j = i+1; j < num.size(); j++) {
                if (valid(num, 0, i, j)) return true;
            }
        }
        return false;
    }
};

