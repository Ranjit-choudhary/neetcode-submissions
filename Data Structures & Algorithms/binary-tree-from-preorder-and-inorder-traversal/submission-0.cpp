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
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int> &preorder,int prestart,int instart,int inend){
        if(instart >inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int idx = mp[preorder[prestart]];
        root->left = solve(preorder,prestart+1,instart,idx-1);
        int leftsize = idx-instart;
        root->right = solve(preorder,prestart+leftsize+1,idx+1,inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return solve(preorder,0,0,inorder.size()-1);
    }
};
