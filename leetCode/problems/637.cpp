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
    map <int, int> count;
    map <int, double> sums;
    vector<double> averageOfLevels(TreeNode* root) {
        countLevel (root, 0);
        vector <double> solution;
        
        for (auto m = count.begin(); m != count.end(); m++) {
            double answer = sums[m->first]/(m->second);
            solution.push_back(answer);
        }
        
        return solution;
    }
    
    void countLevel (TreeNode *node, int level) {
        count[level]++;
        sums[level]+=node->val;
        
        if (node->right) countLevel (node->right, level+1);
        if (node->left) countLevel (node->left, level+1); 
    }
};
