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

class Codec {
   public:
    // Encodes a tree to a single string.

    void solve(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "NULL,";
        } else {
            s += to_string(root->val);
            s += ',';
            solve(root->left,s);
            solve(root->right,s);
        }
    }

    string serialize(TreeNode* root) {
        string s;
        solve(root, s);
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* solve2(string& data, int& i) {
        string temp;
        while (i < data.size() && data[i] != ',') {
            temp += data[i++];
        }
        i++;
        if (temp == "NULL") {
            return NULL;
        }
        int v;
        v = stoi(temp);

        TreeNode* ans = new TreeNode(v);
        ans->left = solve2(data, i);
        ans->right = solve2(data, i);
        return ans;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return solve2(data, i);
    }
};
