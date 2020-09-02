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
    void add (TreeNode* root, int k) {
        if (k < root->val) {
            if (root->left) add(root->left, k);
            else root->left = new TreeNode(k);
        }
        else {
            if (root->right) add(root->right, k);
            else root->right = new TreeNode(k);
        }
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode (preorder[0]);        
        
        int n = preorder.size();
        for (int i = 1; i < n; i++) {
            add(root, preorder[i]);
        }
        
        return root;
    }
};
