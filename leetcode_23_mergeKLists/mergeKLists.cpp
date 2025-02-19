#include <iostream>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        int listsNum = lists.size();
        int emptyListNum = 0;
        int i = 0;
        int min_node_index = 0;
        int min = 0;
        ListNode *res_head = nullptr;
        ListNode *res_tail = nullptr;

        while (true) {
            emptyListNum = 0;
            // 找到第一个非空的链表
            for (i = 0; i < listsNum; i++) {
                if (nullptr != lists[i]) {
                    min_node_index = i;
                    min = lists[min_node_index]->val;
                    break;
                } else {
                    emptyListNum++;
                }
            }

            // 每个链表都为空，遍历结束
            if (emptyListNum == listsNum) {
                break;
            }
            
            // 找到当前最小的元素 
            for (i = min_node_index + 1; i < listsNum; i++) {
                if (nullptr != lists[i]) {
                    if (lists[i]->val < min) {
                        min = lists[i]->val;
                        min_node_index = i;
                    }
                } else {
                    emptyListNum++;
                }
            }

            // 加入结果链表
            if (nullptr == res_head) {
                res_head = lists[min_node_index];
                res_tail = lists[min_node_index];
            } else {
                res_tail->next = lists[min_node_index];
                res_tail = lists[min_node_index];
            }

            if (emptyListNum + 1 < listsNum) {
                // 非空链表不止一个，从原链表删除节点
                lists[min_node_index] = lists[min_node_index]->next;
                res_tail->next = nullptr;
            } else {
                // 非空链表只有一个
                break;
            }
        }
        
        return res_head;
    }
};

int main () {

    ListNode node02(5);
    ListNode node01(4, &node02);
    ListNode node00(1, &node01);

    ListNode node12(4);
    ListNode node11(3, &node12);
    ListNode node10(1, &node11);

    ListNode node21(6);
    ListNode node20(2, &node21);

    vector<ListNode*> lists = {&node00, &node10, &node20};

    Solution solu;
    ListNode* res = solu.mergeKLists(lists);

    while (nullptr != res) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}