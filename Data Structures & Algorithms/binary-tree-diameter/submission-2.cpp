
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
int depth(TreeNode *root){
    if(root == NULL) return 0;
    return 1 + max(depth(root->left),depth(root->right));
}
    int solve(TreeNode* root) {
        if(root == NULL) return 0;
        int a = depth(root->left) + depth(root->right);
        int b = solve(root->left);
        int c = solve(root->right);
        return max({a,b,c});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        return solve(root);
    }
};