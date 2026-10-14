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
    int mod(int a,int b){
        if(a>b) return a-b;
        return b-a;
    }
    int ht(TreeNode* N){
        if(N==NULL) return 0;
        return 1+ max(ht(N->left),ht(N->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return 1;
        if(mod(ht(root->left), ht(root->right)) >1) return false;
        return (isBalanced(root->right) & isBalanced(root->left));
    }
};
