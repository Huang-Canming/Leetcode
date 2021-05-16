#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (nullptr == head || nullptr == head->next)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != slow)
        {
            if (nullptr == fast || nullptr == fast->next)
            {
                return false;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

int main()
{
    ListNode nodeA(3);
    ListNode nodeB(2);
    ListNode nodeC(0);
    ListNode nodeD(-4);

    nodeA.next = &nodeB;
    nodeB.next = &nodeC;
    nodeC.next = &nodeD;
    nodeD.next = &nodeB;

    Solution solution;

    cout << solution.hasCycle(&nodeA) << endl;

    return 0;
}