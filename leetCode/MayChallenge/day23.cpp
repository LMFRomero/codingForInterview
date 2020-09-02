class Solution {
public:
    vector<int> minPair (int a, int b) {
        vector<int> ans(2);
        ans[0] = min(a, b);
        ans[1] = ans[0] == a ? 0 : 1;
        return ans;
    }
    vector<int> maxPair (int a, int b) {
        vector<int> ans(2);
        ans[0] = max(a, b);
        ans[1] = ans[0] == a ? 0 : 1;
        return ans;
    }
    
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n1 = A.size(), n2 = B.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        
        while (true) {
            vector<int> ret, tmp;
            bool flag = true;
            
            while (flag) {
                flag = false;
                while (i < n1 and j < n2 and A[i][1] < B[j][0]) {
                    i++;
                    flag = true;
                }
                while (i < n1 and j < n2 and B[j][1] < A[i][0]) {
                    j++;
                    flag = true;
                }
            }
                       
            if ((i < n1 and j < n2) == false)
                break;
            
            ret = maxPair(A[i][0], B[j][0]);
            tmp.push_back(ret[0]);
            
            ret = minPair(A[i][1], B[j][1]);
            tmp.push_back(ret[0]);
            
            if (ret[1] == 1) {
                j++;
            }
            else {
                i++;
            }
            
            ans.push_back(tmp);
            tmp.clear();
        }
        
        return ans;
        
    }
};
