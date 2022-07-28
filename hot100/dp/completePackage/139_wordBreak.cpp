#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
// 请你判断是否可以利用字典中出现的单词拼接出 s 。
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。


// 是排列问题，所以先遍历背包，后遍历物品

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        // dp[i] : 以s[i-1]结尾的字符串能不能被拆分（不需要用二维数组）
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {   // 遍历背包
            for (int j = 0; j < i; j++) {       // 遍历物品
                string word = s.substr(j, i - j); //substr(起始位置，截取的个数)
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};



// 回溯法比较复杂

class Solution {
private:
    bool backtracking (const string& s,
            const unordered_set<string>& wordSet,
            vector<int>& memory,
            int startIndex) {
        if (startIndex >= s.size()) {
            return true;
        }
        // 如果memory[startIndex]不是初始值了，直接使用memory[startIndex]的结果
        if (memory[startIndex] != -1) return memory[startIndex];
        for (int i = startIndex; i < s.size(); i++) {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, memory, i + 1)) {
                memory[startIndex] = 1; // 记录以startIndex开始的子串是可以被拆分的
                return true;
            }
        }
        memory[startIndex] = 0; // 记录以startIndex开始的子串是不可以被拆分的
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memory(s.size(), -1); // -1 表示初始化状态
        return backtracking(s, wordSet, memory, 0);
    }
};