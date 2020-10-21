class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        int ind;
        
        ans.push_back(0);
        
        for (int i = 1; i <= num; i++) {
            ind = i/2;
            ans.push_back(ans[ind]+(i%2));
        }
        
        return ans;
    }
};
