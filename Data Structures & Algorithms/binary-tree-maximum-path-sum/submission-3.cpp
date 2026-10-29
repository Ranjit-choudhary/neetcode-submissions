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
    int ans=INT_MIN;
    int solve(TreeNode* tree){
        if(tree == NULL) return 0;
        int l = max(0,solve(tree->left));
        int r = max(0,solve(tree->right));
        ans= max({tree->val+l+r,ans});
        return tree->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
