#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *pNodeFast = head;
        ListNode *pNodeSlow = head;

        while (nullptr != pNodeFast->next->next)
        {
            pNodeFast = pNodeFast->next->next;
            pNodeSlow = pNodeSlow->next;
        }

        if (nullptr != pNodeFast->next)
        {
            pNodeFast = pNodeFast->next;
        }

        /* 翻转后半部分链表 */
        

        /* 双指针结点比对 */
        while ()
        {

        }
    }
};

int main()
{
    ListNode node11(1);
    ListNode node12(2);
    node11.next = &node12;

    ListNode node21(1);
    ListNode node22(2);
    ListNode node23(2);
    ListNode node24(1);
    node21.next = &node22;
    node22.next = &node23;
    node23.next = &node24;

    Solution solution;

    cout << solution.isPalindrome(&node11) << endl;
    cout << solution.isPalindrome(&node21) << endl;

    return 0;
}