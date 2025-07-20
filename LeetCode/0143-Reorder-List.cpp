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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        vector<int> v;
        while(curr != nullptr){
            v.push_back(curr->val);
                curr = curr->next;
        }
        vector<int> tmp;
        int n=v.size();
        int arr[n];
        arr[0]= v[0];
        tmp =v;
        int j=1,k=1;
        for(int i = 1;i<n;i++){
            if(i%2 != 0){
                tmp[i]=v[n-j];
                j++;
            }
            else{
                tmp[i] = v[k];
                k++;
            }
        }
        int i =0;
        curr = head;
        while(curr != nullptr){
            curr->val = tmp[i];
            cout<<curr->val<<" ";
                curr = curr->next;
                i++;
        }

    }
};

