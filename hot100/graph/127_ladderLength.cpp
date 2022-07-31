/*
字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：

每一对相邻的单词只差一个字母。
 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
sk == endWord
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

*/

#include <bits/stdc++.h>

using namespace std;

// 单词接龙v1

// 优化的方法，两个set保存已经访问的节点和未访问的节点，到达一个节点的，
// 将该单位逐位替换'a'-'z'，再查看替换后的单词是否在两个set中，最后做相应的处理

// 单向BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 将vector转成unordered_set，提高查询速度
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // 如果endWord没有在wordSet出现，直接返回0
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        // 记录word是否访问过
        unordered_map<string, int> visitMap; // <word, 查询到这个word路径长度>
        // 初始化队列
        queue<string> que;
        que.push(beginWord);
        // 初始化visitMap
        visitMap.insert(pair<string, int>(beginWord, 1));

        while(!que.empty()) {
            string word = que.front();
            que.pop();
            int path = visitMap[word]; // 这个word的路径长度
            for (int i = 0; i < word.size(); i++) {
                string newWord = word; // 用一个新单词替换word，因为每次置换一个字母
                for (int j = 0 ; j < 26; j++) {
                    newWord[i] = j + 'a';
                    if (newWord == endWord) return path + 1; // 找到了end，返回path+1
                    // wordSet出现了newWord，并且newWord没有被访问过
                    if (wordSet.find(newWord) != wordSet.end()
                            && visitMap.find(newWord) == visitMap.end()) {
                        // 添加访问信息
                        visitMap.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};

class Solution {
private:
    bool canConcert(const string& s1, const string& s2)
    {
        int m = s1.size();
        int n = s2.size();
        if(m != n)
            return false;
        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s1[i] != s2[i])
                ++cnt;
            if(cnt > 1)
                return false;
        }
        return cnt == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i)
        {
            if(wordList[i] == beginWord)
            {
                visited[i] = true;
                break;
            }
        }
        queue<string> strQ;
        strQ.push(beginWord);
        int res = 0;
        while(strQ.size() > 0)
        {
            int size = strQ.size();
            ++res;
            while(size-- > 0){
                for(int i = 0; i < wordList.size(); ++i)
                {
                    if(!visited[i])
                    {
                        string s = wordList[i];
                        if(canConcert(s, strQ.front()))
                        {
                            if(s == endWord)
                                return res + 1;
                            visited[i] = true;
                            strQ.push(s);
                        }
                    }
                }
                strQ.pop();
            }
        }
        return 0;
    }
};

// 双向BFS
class Solution {
private:
    bool canConcert(const string& s1, const string& s2)
    {
        int m = s1.size();
        int n = s2.size();
        if(m != n)
            return false;
        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s1[i] != s2[i])
                ++cnt;
            if(cnt > 1)
                return false;
        }
        return cnt == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int endIdx = -1;
        int n = wordList.size();
        for(int i = 0; i < n; ++i)
        {
            if(wordList[i] == endWord)
            {
                endIdx = i;
                break;
            }
        }
        if(endIdx == -1)
            return 0;
        wordList.push_back(beginWord);
        ++n;
        int beginIdx = n - 1;
        queue<int> idxQ1;
        queue<int> idxQ2;
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);
        idxQ1.push(endIdx);
        idxQ2.push(beginIdx);
        visited1[endIdx] = true;
        visited2[beginIdx] = true;
        int cnt = 0;
        while(!idxQ1.empty() && !idxQ2.empty())
        {
            ++cnt;
            if(idxQ1.size() > idxQ2.size())
            {
                swap(idxQ1, idxQ2);
                swap(visited1, visited2);
            }
            int size1 = idxQ1.size();
            while(size1--)
            {
                string s = wordList[idxQ1.front()];
                idxQ1.pop();
                for(int i = 0; i < n; ++i)
                {
                    if(!visited1[i])
                    {
                        if(canConcert(s, wordList[i]))
                        {
                            if(visited2[i])
                                return cnt + 1;
                            else
                            {
                                visited1[i] = true;
                                idxQ1.push(i);
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};