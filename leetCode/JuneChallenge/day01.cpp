class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
        
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        
        invertTree(root->right);
        invertTree(root->left);
        
        return root;
    }
};
