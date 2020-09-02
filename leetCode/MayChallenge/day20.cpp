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
    pair <int, int> func (TreeNode *root, const int k, int value) {
        if (root == nullptr)
            return {0, -1};
        
        pair <int, int> ret = func(root->left, k, value);
        if (ret.second != -1)
            return ret;
        
        int nodeCounter = ret.first+1;
        int nodeValue = nodeCounter+value;
        int ans = nodeValue == k ? root->val : -1;
        
        if (ans == -1) ret = func(root->right, k, nodeValue);
        if (ret.second != -1) ans = ret.second;
        
        int rightCounter = ret.first;
        
        return {nodeCounter+rightCounter, ans};
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return func(root, k, 0).second;    
    }
};
