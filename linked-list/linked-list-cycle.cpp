class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        while (ptr1 && ptr2 && ptr2->next) {
            if (ptr1 == ptr2) return true;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        return false; 
    }
};