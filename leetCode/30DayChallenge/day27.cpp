class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int I = matrix.size();
        if (I == 0 or matrix[0].empty())
            return 0;
        
        int J = matrix[0].size();
        
        vector<vector<int>> dp (I, vector<int>(J));
        int answer = 0;
        
        for (int i = 0; i < I; i++) {
            for (int j = 0; j < J; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                
                    if (i > 0 and j > 0) {
                        dp[i][j] += min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }

                    answer = max(answer, dp[i][j]);
                }
            }
        }
        
        return answer*answer;
    }
};
