#include <set>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

#if 1
class Solution {
    private:
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
        struct TrieNode {
            string word;
            unordered_map<char, TrieNode*> subTrieNode;
            TrieNode() : word("") {}
        };
        
        void buildTrieTree (vector<string>& words, TrieNode *root) {
            TrieNode *curNode = nullptr;
            
            // 根据 words 构建字典树
            for (string w : words) {
                curNode = root;
                for (char c : w) {
                    // 逐个处理 w 中的字符，一个字符对应字典树中的一层（一个节点）
                    if (0 == curNode->subTrieNode.count(c)) {
                        // 对应的子节点不存在，就新建一个子节点
                        curNode->subTrieNode[c] = new TrieNode();
                    }
                    curNode = curNode->subTrieNode[c];
                }
                curNode->word = w;
            }
            
            return;
        }
        
        void dfsWord (vector<vector<char>> &board, int i, int j, TrieNode *curNode, set<string> &resSet) {
            if (curNode->word.size() > 0) {
                // 找到了在 words 中的一个字符串，这里不 return，继续向下搜索
                resSet.insert(curNode->word);
            }
        
            int nextI = 0, nextJ = 0;
            char nextC, curC;
            for (int k = 0; k < 4; k++) {
                nextI = i + dirs[k][0];
                nextJ = j + dirs[k][1];
                if (nextI < 0 || nextI >= board.size() || nextJ < 0 || nextJ >= board[0].size()) {
                    // 超出边界，搜索方向不对，直接跳过
                    continue;
                }

                nextC= board[nextI][nextJ];
                if ('#' == nextC) {
                    // 已经搜索过，跳过
                    continue;
                }
                
                if (0 != curNode->subTrieNode.count(nextC)) {
                    // 字符在当前路径上存在，搜索方向是对的，继续向下搜索
                    curC = board[i][j];
                    board[i][j] = '#';
                    dfsWord(board, nextI, nextJ, curNode->subTrieNode[nextC], resSet);
                    board[i][j] = curC;
                }
            }
            
            return;
        }
    
    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            TrieNode root;              // 字典树根节点，不对应任何字符，word 必为空
            set<string> resSet;
            int m = board.size(), n = board[0].size();
            char c;

            buildTrieTree(words, &root);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    c = board[i][j];
                    if (0 != root.subTrieNode.count(c)) {
                        dfsWord(board, i, j, root.subTrieNode[c], resSet);
                    }
                }
            }
            
            vector<string> resVec;
            for (string word : resSet) {
                resVec.push_back(word);
            }
            return resVec;
        }
    };
#else
class Solution {
private:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    bool searchChar(vector<vector<char>>& board, int m, int n, vector<vector<bool>> &visited, pair<int, int>& cPos, 
                    string& word, int index) {
        if (index >= word.length()) {
            return true;
        }

        bool exist = false;
        pair<int, int> sPos;
        for (pair<int, int> dir : dirs) {
            sPos.first = cPos.first + dir.first;
            sPos.second = cPos.second + dir.second;
            if (0 <= sPos.first && sPos.first < m &&
                0 <= sPos.second && sPos.second < n && 
                false == visited[sPos.first][sPos.second] &&
                board[sPos.first][sPos.second] == word[index]) {
                visited[sPos.first][sPos.second] = true;
                exist = searchChar(board, m, n, visited, sPos, word, index + 1);
                visited[sPos.first][sPos.second] = false;
                if (exist) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // 记录字符在 board 中的位置
        unordered_map<char, vector<pair<int, int>>> cPosHash;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (cPosHash.end() == cPosHash.find(board[i][j])) {
                    cPosHash[board[i][j]] = vector<pair<int, int>>(1, pair<int, int>(i, j));
                } else {
                    cPosHash[board[i][j]].push_back(pair<int, int>(i, j));
                }
            }
        }

        bool exist = false;
        // 检索 words 中的单词在 board 中是否存在
        for (string word : words) {
            // 判断 word 的开头字符在 board 中是否存在
            if (cPosHash.end() == cPosHash.find(word[0])) {
                continue;
            }
            
            // 从 word 的开头字符在 board 中的位置开始检索
            for (pair<int, int> cPos : cPosHash[word[0]]) {
                visited[cPos.first][cPos.second] = true;
                exist = searchChar(board, m, n, visited, cPos, word, 1);
                visited[cPos.first][cPos.second] = false;
                if (exist) {
                    res.push_back(word);
                    break;
                }
            }
        }

        return res;
    }
};
#endif

int main () {
    Solution solu;
    vector<vector<char>> board1 = {{'a','b'}};
    vector<string> words1 = {"ba"};
    vector<string> res1 = solu.findWords(board1, words1);
    for (string str : res1) {
        cout << str << endl;
    }

    cout << "~~~~~~~" << endl;

    vector<vector<char>> board2 = {{'a','b','c'}, {'a','e','d'}, {'a','f','g'}};
    vector<string> words2 = {"abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"};
    vector<string> res2 = solu.findWords(board2, words2);
    for (string str : res2) {
        cout << str << endl;
    }

    return 0;
}