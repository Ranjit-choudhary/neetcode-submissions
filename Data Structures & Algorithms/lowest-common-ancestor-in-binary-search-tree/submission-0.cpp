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
    bool contains(TreeNode *t,int x){
        if(t == NULL) return false;
        if(t->val == x) return true;
        return contains(t->left,x) || contains(t->right,x);
    }
    TreeNode* ans;
    void solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(contains(root,p->val ) && contains(root,q->val )){
            ans = root;
        }
        else return;
        
        solve(root->left,p,q);
        solve(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return ans;
    }
};
