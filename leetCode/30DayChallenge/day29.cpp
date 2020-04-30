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
    //maximum, maxDepth
    pair <int, int> path (TreeNode *root) {
        if (root == nullptr)
            return {-1e9+5,0};
        
        pair <int, int> left, right;
        left = path(root->left);
        right = path(root->right);
        
        int maximumDepth = max(max(left.second, right.second) + root->val, root->val);
        int maximum = max(left.first, right.first);
        maximum = max(maximum, maximumDepth);
        maximum = max(maximum, left.second+right.second+root->val);
        
        return {maximum, maximumDepth};
    }
    
    int maxPathSum(TreeNode* root) {
        return path(root).first;
    }
};
