#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for (int i = 0; i < (int)strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            mp[key].emplace_back(strs[i]);
        }

        for (auto iter = mp.begin(); iter != mp.end(); iter++)
        {
            res.emplace_back(iter->second);
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    solution.groupAnagrams(strs);

    return 0;
}