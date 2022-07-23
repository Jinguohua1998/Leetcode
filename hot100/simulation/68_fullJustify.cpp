#include <bits/stdc++.h>

using namespace std;

// 文本左右对齐
// 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
// 文本的最后一行应为左对齐，且单词之间不插入额外的空格。

class Solution {
private:
    string join(vector<string> &words, int left, int right, string sep)
    {
        string s = words[left];
        for(int i = left + 1; i < right; ++i)
        {
            s += sep + words[i];
        }
        return s;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int right = 0, n = words.size();
        while(true)
        {
            int left = right;
            int sumLen = 0;
            while(right < n && sumLen + words[right].size() + right - left <= maxWidth)
            {
                sumLen += words[right++].size();
            }
            if(right == n)
            {
                string s = join(words, left, n, " ");
                res.push_back(s + string(maxWidth - s.size(), ' '));
                return res;
            }

            int numWords = right - left;
            int numSpaces = maxWidth - sumLen;

            if(numWords == 1)
            {
                res.push_back(words[left] + string(numSpaces, ' '));
                continue;
            }

            int avgSpaces = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);
            string s1 = join(words, left, left +extraSpaces + 1, string(avgSpaces +1, ' '));
            string s2 = join(words, left + extraSpaces + 1, right, string(avgSpaces, ' '));
            res.push_back(s1 + string(avgSpaces, ' ') + s2);
        }
    }
};