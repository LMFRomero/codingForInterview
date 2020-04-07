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

/* This is a iterative way to do, which I didn't know. So I'm writing it down here to practice this way
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> answer;
        vector <TreeNode*> nodes;

        nodes.push_back(root);
        double sum;
        double avg;

        while (nodes.empty() == false) {

            sum = 0;
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                TreeNode *current_node = nodes[0];
                nodes.erase(nodes.begin());
                if (current_node->right) nodes.push_back(current_node->right);
                if (current_node->left) nodes.push_back(current_node->left);
                sum += current_node->val;

            }

            avg = sum/size;
            answer.push_back(avg);
        }

        return answer;
    }
};

*/
