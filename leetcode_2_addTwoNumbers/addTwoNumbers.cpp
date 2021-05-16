#include <iostream>
#include <algorithm>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *pNodeTmp = nullptr, *pNodeHead = nullptr;
        vector<int> vec1, vec2;
        int valTmp1 = 0, valTmp2 = 0, carryOver = 0, valRes = 0;

        pNodeTmp = l1;
        while (nullptr != pNodeTmp)
        {
            vec1.push_back(pNodeTmp->val);
            pNodeTmp = pNodeTmp->next;
        }

        pNodeTmp = l2;
        while (nullptr != pNodeTmp)
        {
            vec2.push_back(pNodeTmp->val);
            pNodeTmp = pNodeTmp->next;
        }

        for (int i = 0; i < max((int)vec1.size(), (int)vec2.size()) + 1; i++)
        {
            i >= (int)vec1.size() ? valTmp1 = 0 : valTmp1 = vec1[i];
            i >= (int)vec2.size() ? valTmp2 = 0 : valTmp2 = vec2[i];
            if (valTmp1 + valTmp2 + carryOver > 9)
            {
                valRes = valTmp1 + valTmp2 + carryOver - 10;
                carryOver = 1;
            }
            else
            {
                valRes = valTmp1 + valTmp2 + carryOver;
                carryOver = 0;
            }

            if ((i == max((int)vec1.size(), (int)vec2.size())) && (0 == valRes))
            {
                break;
            }

            if (0 == i)
            {
                pNodeHead = new ListNode(valRes);
                pNodeTmp = pNodeHead;
            }
            else
            {
                pNodeTmp->next = new ListNode(valRes);
                pNodeTmp = pNodeTmp->next;
            }
        }

        return pNodeHead;
    }
};

int main()
{
    Solution solution;

    return 0;
}