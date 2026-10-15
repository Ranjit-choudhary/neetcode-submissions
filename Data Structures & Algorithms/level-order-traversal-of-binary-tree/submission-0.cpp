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
int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
void solve(TreeNode* root, int ht,vector<vector<int>> &ans){
    if(root == NULL) return;
    ans[ht].push_back(root->val) ;

    solve(root->left,ht+1,ans);
    solve(root->right,ht+1,ans);
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        int size=  maxDepth(root);
        vector<vector<int>> ans(size);
        solve(root,0,ans);
        return ans;
    }
};
