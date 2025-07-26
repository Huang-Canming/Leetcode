#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.length() < p.length()) {
            return res;
        }
        
		// 统计 p 中各个字符的个数，和初始滑动窗口中 s 中各个字符的个数
        vector<int> p_count(26, 0);
        vector<int> s_count(26, 0);
        for (int i = 0; i < p.length(); i++) {
            p_count[p[i] - 'a']++;
            s_count[s[i] - 'a']++;
        }

        int left = 0;
		int right = left + p.length() - 1;
		while (true) {
            #if 0
			bool anagrams = true;
			// 判断 left~right 之间窗口内，各个字符数和 p 中的是否相等
			for (int i = 0; i < 26; i++) {
				if (s_count[i] != p_count[i]) {
					anagrams = false;
					break;
				}
			}
			if (anagrams) {
				res.push_back(left);
			}
            #else
            if (s_count == p_count) {
				res.push_back(left);
			}
            #endif
			
			// 窗口从左向右滑动，更新 left~right 之间各个字符数的变化
			s_count[s[left] - 'a']--;
			left++;
			right++;
            if (right >= s.length()) {
                break;
            } else {
                s_count[s[right] - 'a']++;
            }
		}

        return res;
    }
};

int main() {
    Solution s;
    vector<int> res1 = s.findAnagrams("cbaebabacd", "abc");
    for (int i : res1) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> res2 = s.findAnagrams("abab", "ab");
    for (int i : res2) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> res3 = s.findAnagrams("aaaaaaaaaa", "aaaaaaaaaaaaa");
    for (int i : res3) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}