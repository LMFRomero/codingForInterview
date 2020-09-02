class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp (n, vector<int>(m));
        
        int ans;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i] == B[j]) {
                    dp[i][j]++;
                    
                    if (i < n-1 and j < m-1) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
                }
                else {
                    if (i < n-1) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                    if (j < m-1) dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
                }
                
                ans = max (ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};
