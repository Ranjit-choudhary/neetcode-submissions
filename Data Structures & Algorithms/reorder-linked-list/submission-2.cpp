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
        if(head == NULL) return;
        ListNode* tail=head,*slow =head;

        while(tail->next && tail->next->next) {
            tail = tail->next->next;
            slow=slow->next;
            }
        if(tail->next) tail = tail->next;
        ListNode *second = slow->next;
        slow->next = NULL;
        slow = second;
        ListNode *prev = NULL,*curr =slow;
        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // tail = prev;
        while(tail){
            ListNode *temp1 = head->next,*temp2=tail->next;
            
            head->next =tail;
            tail->next = temp1;

            head = temp1;
            tail = temp2;

        }



    }
};
