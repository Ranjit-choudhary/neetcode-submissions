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
int count =1;

    int ele(TreeNode* r){
        if(r==NULL) return 0;
        return 1 + ele(r->left) + ele(r->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        int left = ele(root->left);
        int right = ele(root->right);
        if(k== 1+left) return root->val;
        if(left>=k) return kthSmallest(root->left,k);
        else return kthSmallest(root->right,k-(left+1));
    }
};
