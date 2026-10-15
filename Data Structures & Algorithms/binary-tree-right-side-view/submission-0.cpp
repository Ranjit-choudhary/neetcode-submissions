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
void solve(TreeNode* root, int ht,vector<vector<int>> &ans){
    if(root == NULL) return;
    if (ht == ans.size()) ans.push_back({});
    ans[ht].push_back(root->val) ;

    solve(root->left,ht+1,ans);
    solve(root->right,ht+1,ans);
}

    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,0,ans);
        vector<int> a;
        for(int  i=0;i<ans.size();i++){
            a.push_back(ans[i][ans[i].size() -1]);
        }
        return a;
    }
};
