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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> todelete(nums.begin(),nums.end());

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *curr = head;
        ListNode *prev = dummy;
        while(curr != nullptr){

            if(todelete.count(curr->val)){
                curr = curr->next; 
                prev->next = curr;
            }else{
                prev=curr;
                curr = curr->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
