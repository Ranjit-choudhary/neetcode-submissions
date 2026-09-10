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
int maxD =0;
int depth(TreeNode *root){
    if(root == NULL) return 0;
    int a =depth(root->left);
    int b =depth(root->right);
    maxD= max(maxD,a+b);
    return 1+max(a,b);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        depth(root);
        return maxD;
    }
};
