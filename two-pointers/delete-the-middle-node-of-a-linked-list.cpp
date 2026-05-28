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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;
        ListNode* i = head;
        ListNode* iPrev = nullptr;
        ListNode* j = head;
        while (i && j && j->next) {
            iPrev = i;
            i = i->next;
            j = j->next;
            if (j) j = j->next;
        }
        iPrev->next = i->next;
        delete i;
        return head;
        
        
    }
};