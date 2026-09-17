/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* temp = head;
        Node* dummy = new Node(0);
        Node *ptr = dummy;
        while(temp != NULL){
            Node* x = new Node(0);
            ptr->next = x;
            ptr = ptr->next;
            mp[temp] = ptr;
            temp = temp->next;
        }
        ptr = dummy;
        ptr=ptr->next;
        while(head !=NULL){
            ptr->val = head->val;
            ptr->random = mp[head->random];
            head = head->next;
            ptr=ptr->next;
        }
        ptr = (dummy->next);
        return ptr;
    }
};
