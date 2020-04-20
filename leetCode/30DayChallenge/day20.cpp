/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* create_node (int n) {
        TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
        node->val = n;
        node->right = NULL;
        node->left = NULL;
        return node;
    }
    
    void add_node (TreeNode *root, int value) {
        if (value > root->val) {
            if (root->right != NULL) add_node(root->right, value);
            else root->right = create_node(value);
        }
        else {
            if (root->left != NULL) add_node(root->left, value);
            else root->left = create_node(value);
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return NULL;
        
        TreeNode *root = create_node(preorder[0]);
        int size = preorder.size();
        
        for (int i = 1; i < size; i++) {
            add_node(root, preorder[i]);
        }
        
        return root;
    }
};
