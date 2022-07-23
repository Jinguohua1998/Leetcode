#include <bits/stdc++.h>

using namespace std;

// 单词接龙v1

// 优化的方法，两个set保存已经访问的节点和未访问的节点，到达一个节点的，
// 将该单位逐位替换'a'-'z'，再查看替换后的单词是否在两个set中，最后做相应的处理

// 单向BFS
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