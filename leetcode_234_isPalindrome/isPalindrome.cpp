#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *node = head;
        vector<int> listVal;
        int nodeCnt = 0;

        while (nullptr != node)
        {
            listVal.push_back(node->val);
            nodeCnt++;
            node = node->next;
        }

        for (int i = 0; i < nodeCnt / 2; i++)
        {
            if (listVal[i] != listVal[nodeCnt - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};