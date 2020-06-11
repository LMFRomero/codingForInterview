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
    int x_k = -1;
    int y_k = -1;
    
    bool rec(TreeNode* root, int x, int y, int k) {
        if (root == nullptr)
            return false;
        
        if (root->left != nullptr and root->right != nullptr) {
            if (root->left->val == x || root->left->val == y) {
                if (root->right->val == x || root->right->val == y)
                    return false;
            }
        }
        
        if (root->val == x) {
            if (k == y_k)
                return true;
            x_k = k;
            return false;
        }
        
        else if (root->val == y) {
            if (k == x_k)
                return true;
            y_k = k;
            return false;
        }
        
        else return rec(root->left, x, y, k+1) or rec(root->right, x, y, k+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        return rec(root, x, y, 0);
    }
};
