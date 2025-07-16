#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> nodeSet;
		ListNode preHead(0);
        preHead.next = head;
		ListNode *node = &preHead;
		ListNode *res = nullptr;
		
		while (true) {
			if (nullptr == node->next) {
				break;
			} else {
				node = node->next;
				if (nodeSet.end() != nodeSet.find(node)) {
					res = node;
					break;
				} else {
					nodeSet.insert(node);
				}
			}
		}
		
		return res;
    }
};

int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    Solution s;
    ListNode *node = s.detectCycle(head);
    cout << node->val << endl;
    return 0;
}