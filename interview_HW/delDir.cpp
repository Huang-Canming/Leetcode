#include <vector>
#include <string>

using namespace std;

void delParentDir (vector<string> &aimDirs, int level, int maxDepth, vector<pair<int, string>> &tree) {
    for (int i = 0; i < level; i++) {
        maxDepth == tree[i].first
        for (string dir : aimDirs) {
            if (dir == tree[i].second) {
                for (int j = i; j >= 0; j--) {
                    
                }
            }
        }

        

    }
    return;
}

void delDir (vector<string> &aimDirs, int level, int maxDepth, vector<pair<int, string>> &tree) {
    for (int i = 0; i < level; i++) {
        maxDepth == tree[i].first
        for (string dir : aimDirs) {
            if (dir == tree[i].second) {
                for (int j = i; j >= 0; j--) {

                }
            }
        }

        

    }
    return;
}

int main () {
    vector<string> aimDir;

    int level = 0;
    cin >> level;

    int maxDepth = 0;
    vector<pair<int, string>> tree(level);
    for (int i = 0; i < level; i++) {
        string str;
        cin >> str;
        int depth = 0;
        if (str.length() > 2) {
            for (int j = 0; j < str.length(); j += 2) {
                if ('|' == str[j] && '-' == str[j + 1]) {
                    depth++;
                } else {
                    tree[i].first = depth;
                    tree[i].second = str.substr(j, str.length() - j);
                }
            }
        }
        maxDepth = max(depth, maxDepth);
    }

    delDir(aimDir, level, maxDepth, tree);

    return 0;
}