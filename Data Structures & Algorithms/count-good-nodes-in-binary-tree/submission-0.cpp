/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int count =0;
    void solve(TreeNode* r,int m){
        if(r == NULL) return;
        if(r->val >= m){
        count++;
        } 
        m = max(m,r->val);

        solve(r->left,m);
        solve(r->right,m);
    }
    int goodNodes(TreeNode* root) {
        solve(root,INT_MIN);
        return count;
    }
};
