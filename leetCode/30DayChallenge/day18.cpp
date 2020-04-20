class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int INF = 1e9+5;
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        vector <vector<int>> dp(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0) {
                    dp[i][j] = grid[i][j];
                }
                else {
                    dp[i][j] = grid[i][j] + min(i ? dp[i-1][j] : INF, j ? dp[i][j-1] : INF);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
