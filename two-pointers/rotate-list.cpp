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
    ListNode* rotateRight(ListNode* head, int k) {
        // Let n = length of linked list
        // First, let k = k % n
        // first (n - k) remain unchanged in order
        // the (n-k)th element loses next pointer (becomes last element)
        // last k elements also remain unchanged in order
        // last element points to head
        if (!head) return head;
        int n = 1;
        ListNode* last = head;
        while (last->next) {
            n++;
            last = last->next;
        }
        k = k % n;
        if (k == 0) return head;
        ListNode* nkthElement = head;
        for (int i = 0; i < n - k - 1; i++) {
            nkthElement = nkthElement->next;
        }
        ListNode* toReturn = nkthElement->next;
        nkthElement->next = nullptr;
        last->next = head;
        return toReturn;
    }
};