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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast ahead by n+1 steps so that when fast hits end,
        // slow is just before the node to remove
        for (int i = 0; i < n + 1; ++i) {
            fast = fast->next;
        }
        while(fast != nullptr){
            fast=fast->next;
            slow=slow->next;
        }

         ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;
         return dummy.next;
    }
};
