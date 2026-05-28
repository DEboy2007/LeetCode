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
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return carryOver(l1, l2, nullptr, nullptr, 0);
    }

    ListNode* carryOver(ListNode* num1, ListNode* num2, ListNode* result, ListNode* curr, int prevCarry) {
        if (num1 == nullptr && num2 == nullptr && prevCarry == 0) {
            return result;
        }

        int num1val = num1 != nullptr ? num1->val : 0;
        int num2val = num2 != nullptr ? num2->val : 0;

        if (curr == nullptr) {
            curr = new ListNode();
            result = curr;
        } else {
            curr->next = new ListNode();
            curr = curr->next;
        }

        curr->val = (num1val + num2val + prevCarry) % 10;
        int carryVal = (num1val + num2val + prevCarry) / 10;
        if (num1 != nullptr) {
            num1 = num1->next;
        }
        if (num2 != nullptr) {
            num2 = num2->next;
        }
        return carryOver(num1, num2, result, curr, carryVal);
    }
};