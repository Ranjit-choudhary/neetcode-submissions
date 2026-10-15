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
    int solve(TreeNode* r,int m){
        if(r == NULL) return 0;
        int g =0;
        if(r->val >= m){
        g =1;
        } 
        m = max(m,r->val);

        return g + solve(r->left,m) + solve(r->right,m);
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};
