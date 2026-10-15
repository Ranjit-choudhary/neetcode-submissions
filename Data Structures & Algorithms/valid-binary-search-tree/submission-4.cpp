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
    bool solve(TreeNode* r,int minval,int maxval){
        if(r == NULL) return true;
        if(r->val <= minval || r->val >=maxval) return false;
        minval = min(minval,r->val);
        maxval = max(maxval,r->val);
        return solve(r->left,minval,r->val) && solve(r->right,r->val,maxval);
    }
    bool isValidBST(TreeNode* r) {
         if(r == NULL) return true;
        return solve(r->left,INT_MIN,r->val) && solve(r->right,r->val,INT_MAX);
    }
};
