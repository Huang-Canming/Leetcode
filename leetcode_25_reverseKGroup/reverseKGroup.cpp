/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* delAfterNode(ListNode* node){
    if (nullptr == node->next) {
        return nullptr;
    } else {
        ListNode* delNode = node->next;
        node->next = delNode->next;
        return delNode;
    }
}

void addAfterNode(ListNode* node, ListNode* addNode){
    addNode->next = node->next;
    node->next = addNode;
    return;
}

bool reverseKNodes(ListNode *preNode, ListNode *group, int k) {
    bool finish = false;
    int i = 0;
    ListNode *tmp = nullptr;
    // 把 k - 1 个元素放到 group 指向元素的前面，完成翻转
    for (i = 0; i < k - 1; i++) {
        tmp = delAfterNode(group);
        if (nullptr == tmp) {
            break;
        }
        addAfterNode(preNode, tmp);
    }

    // 链表处理完成：“最后的元素少于K个”或“最后的K个元素正好完成翻转”
    if (nullptr == tmp || nullptr == group->next) {
        finish = true;
        
        // 可翻转的少于 k 个元素，重新翻转恢复原顺序
        if (nullptr == tmp) {
            group = preNode->next;
            for (i = 0; i < k - 1; i++) {
                tmp = delAfterNode(group);
                if (nullptr == tmp) {
                    break;
                }
                addAfterNode(preNode, tmp);
            }
        }
    }

    return finish;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    // 翻转最开始的 K 个元素
    ListNode preHead(0, head);
    ListNode *group = head;
    bool finish = reverseKNodes(&preHead, group, k);

    // 翻转下一组元素
    ListNode *preNode = nullptr;
    while (!finish) {
        preNode = group;
        group = group->next;
        finish = reverseKNodes(preNode, group, k);
    }
    
    return preHead.next;
} 
};