struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode *nodeNext = node->next;
        node->val = nodeNext->val;
        node->next = nodeNext->next;

        return;
    }
};