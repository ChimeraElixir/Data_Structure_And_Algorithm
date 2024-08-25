class Solution {
public:
    int solve(int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (n == 0 && m >= 0 && m < matrix[0].size()) {
            return matrix[n][m];  
        }
        if (n < 0 || m < 0 || m >= matrix[0].size()) {
            return 1e9; 
        }
        if (dp[n][m] != -1) {
            return dp[n][m];  
        }

        int up = solve(n-1, m, matrix, dp) + matrix[n][m];
        int left = solve(n-1, m-1, matrix, dp) + matrix[n][m];
        int right = solve(n-1, m+1, matrix, dp) + matrix[n][m];

        return dp[n][m] = min(up, min(left, right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int m = matrix[0].size();
        // int ans = INT_MAX;
        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // for (int i = 0; i < m; i++) {
        //     ans = min(ans, solve(n-1, i, matrix, dp));
        // }
        // return ans;
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (i == 0) {
                    dp[i][j] = matrix[i][j];  // Base case: first row.
                } 
                else {
                    int up = dp[i-1][j] + matrix[i][j];
                    int left = (j > 0) ? dp[i-1][j-1] + matrix[i][j] : INT_MAX;
                    int right = (j < m-1) ? dp[i-1][j+1] + matrix[i][j] : INT_MAX;

                    dp[i][j] = min(up, min(left, right));
                }
            }
        }
    
        int ans = INT_MAX;
        for(int j = 0; j < m; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};
