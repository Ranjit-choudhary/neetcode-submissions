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
    bool hasCycle(ListNode* head) {
        if(head == NULL || head->next == NULL) return 0;
        ListNode* temp1= head,*temp2=head->next;
        while(temp2 != NULL && temp2->next != NULL){
            if(temp2== temp1){
                return true;
            }
            temp1=temp1->next;
            temp2 = temp2->next->next;
        }
        return false;
    }
};
