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
    bool sequence (TreeNode *root, int size, int cur, vector<int>& arr) {
        if (root == nullptr)
            return false;
        
        if (root->val != arr[cur])
            return false;
        
        cur++;
        
        if (size == cur)
            return (root->left == nullptr and root->right == nullptr);
        
        return sequence(root->right, size, cur, arr) or sequence(root->left, size, cur, arr);
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        int size = arr.size();
        
        return sequence(root, size, 0, arr);
    }
};
