#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int checkDiff(string word1, string word2) {
        int diffCnt = 0;
        for (int k = 0; k < word1.length(); k++) {
            if (word1[k] != word2[k]) {
                diffCnt++;
                if (diffCnt > 1) {
                    break;
                }
            }
        }
        return diffCnt;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // hash: string -> pair< 从 begin 开始的距离, vector<只差一个字符的 string> >
        unordered_map<string, pair<int, vector<string>>> wordGraph;
        
        wordGraph[beginWord].first = 1;
        for (int i = 0; i < wordList.size(); i++) {
            if (beginWord != wordList[i]) {
                wordGraph[wordList[i]].first = 0;
                // 判断 wordList[i] 是否是 beginWord 的相邻单词
                if (1 == checkDiff(beginWord, wordList[i])) {
                    wordGraph[beginWord].second.push_back(wordList[i]);
                }
                // 在 wordList 中找到 wordList[i] 的相邻单词
                for (int j = 0; j < wordList.size(); j++) { 
                    if (i != j) {
                        if (1 == checkDiff(wordList[i], wordList[j])) {
                            wordGraph[wordList[i]].second.push_back(wordList[j]);
                        }
                    }
                }
            }
        }

        queue<string> searchQue;
        searchQue.push(beginWord);
        while(!searchQue.empty()) {
            string word = searchQue.front();
            searchQue.pop();
            // 处理相邻单词
            for (string adjWord : wordGraph[word].second) {
                // 找到最终单词
                if (endWord == adjWord) {
                    return wordGraph[word].first + 1;
                }
                // 只把从没有访问过的单词加入队列（如果二次访问，不可能计算出更短的路径）
                if (0 == wordGraph[adjWord].first) {
                    searchQue.push(adjWord);
                    wordGraph[adjWord].first = wordGraph[word].first + 1;
                }
            }
        }

        return 0;
    }
};

int main () {
    Solution solu;
    string beginWord1 = "hit";
    string endWord1 = "cog";
    vector<string> wordList1 = {"hot","dot","dog","lot","log","cog"};
    cout << solu.ladderLength(beginWord1, endWord1, wordList1) << endl;

    string beginWord2 = "hit";
    string endWord2 = "cog";
    vector<string> wordList2 = {"hot","dot","dog","lot","log"};
    cout << solu.ladderLength(beginWord2, endWord2, wordList2) << endl;

    string beginWord3 = "a";
    string endWord3 = "c";
    vector<string> wordList3 = {"a","b","c"};
    cout << solu.ladderLength(beginWord3, endWord3, wordList3) << endl;
    return 0;
}