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
        ListNode* tail=head;
        int count =0;

        while(tail) {
            count++;
            tail = tail->next;
            }
            cout<<count<<endl;
        if(n==count) return head->next;
        count = count-n;

        ListNode *temp = head;
        int c=1;
        while(temp){
            if(c==count){
                temp->next = temp->next->next;
                break;
            }
            c++;
            temp= temp->next;
        }
        return head;
    }
};
