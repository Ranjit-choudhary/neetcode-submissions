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
int count =0;
int ans=-1;
int K;
void inorder(TreeNode* r){
    if(r==NULL) return;
    if(count >K) return;
    inorder(r->left);
    count++;
    if(count == K) {
        ans = r->val;
    }
    if(count>=K) return;
    inorder(r->right);
    if(count>=K) return;
}
    int kthSmallest(TreeNode* root, int k) {
     K=k;   
     inorder(root);
     return ans;
    }
};
