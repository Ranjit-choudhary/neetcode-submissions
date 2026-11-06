/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        vector<Node*> st;
        unordered_map<int,pair<Node*,bool>> mp;
        st.push_back(node);

        Node* ans = new Node(1);
        mp[1] = {ans,false};
        // mp[1].second() = false;

        while(!st.empty()){
            Node* temp = st.back();
        st.pop_back();
            if(mp.count(temp->val)  == 0){
                Node* newnode = new Node(temp->val);
                mp[temp->val] = {newnode,false};
                // mp[temp->val].second() = false;
            }
            if(mp[temp->val].second == true) continue;
            mp[temp->val].second = true;

            Node* newnode = mp[temp->val].first;
                    for(int i=0;i<(temp->neighbors).size();i++){
                        if(mp.count(temp->neighbors[i]->val) == 0){
                            Node* t= new Node(temp->neighbors[i]->val);
                            mp[temp->neighbors[i]->val] = {t,false};
                            // mp[temp->neighbors[i]->val].second() = false;
                        }
                        newnode->neighbors.push_back(mp[temp->neighbors[i]->val].first);
                        st.push_back(temp->neighbors[i]);
                }
        }
        return ans;
    }
};
