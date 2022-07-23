// 每个单词的长度都一样，所以将滑动窗口的情况按照单词的长度分类
// 三种情况：
// 1. 匹配成功后，则滑动窗口向后移动一个wordLen
// 2. 虽然匹配成功,但是该单词匹配的次数超出限制，则移到该窗口的该单词第一次出现的位置后面
// 3. 有一个单词匹配失败（不存在该单词），则滑动窗口的头部移到该单词的后一个单词处

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordNum = words.size();
        if(wordNum == 0)
            return res;
        int wordLen = words[0].size();
        unordered_map<string, int> allWords;
        for(const auto& word : words){
            ++allWords[word];
        }
        for(int j = 0; j < wordLen; ++j){
            unordered_map<string, int> hasWords;
            int num = 0; // 记录已经匹配的单词数量
            // 注意 ：hasWords和num必须在循环内初始化
            int i = j;
            // i 为滑动窗口的左端点
            while(i < s.length() - wordNum * wordLen + 1){
                string word = s.substr(i + num * wordLen, wordLen);
                if(allWords.find(word) != allWords.end()){
                //可以匹配到数据（1.匹配的单词超出限制 2.没有超出限制）
                    ++hasWords[word];
                    ++num;
                    while(hasWords[word] > allWords[word]){
                    // 单词次数超了
                        string delWord = s.substr(i, wordLen);
                        --hasWords[delWord];
                        --num;
                        i += wordLen;
                    }
                }else{
                // 不能匹配到数据，直接清空
                    hasWords.clear();
                    i += (num+1)*wordLen;
                    //注意 ：这里是（num+1）*wordLen 而不是 num*wordLen + 1
                    num = 0;
                }
                if(num == wordNum){
                // 成功匹配到一组
                    res.push_back(i);
                    if(i < s.length() - wordNum * wordLen + 1){
                        --hasWords[s.substr(i, wordLen)];
                        i += wordLen;
                        --num;
                    }
                }    
            }
        }
        return res;
    }
};

