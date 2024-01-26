class Solution {
public:
    int M=1e9+7;
    int solve(int m, int n,int maxMove, int startRow, int startColumn,vector<vector<vector<int>>> &dp){
        if(startColumn<0 || startColumn>=n || startRow<0 || startRow>=m){
            return 1;
        }
        if(maxMove == 0) return 0;
        if(dp[maxMove][startRow][startColumn]!=-1) return dp[maxMove][startRow][startColumn];

    
        long long paths = 0;

        paths = (paths + solve(m, n, maxMove - 1, startRow, startColumn - 1, dp)) % M;
        paths = (paths + solve(m, n, maxMove - 1, startRow - 1, startColumn, dp)) % M;
        paths = (paths + solve(m, n, maxMove - 1, startRow + 1, startColumn, dp)) % M;
        paths = (paths + solve(m, n, maxMove - 1, startRow, startColumn + 1, dp)) % M;

        dp[maxMove][startRow][startColumn] = paths;

        return dp[maxMove][startRow][startColumn];
        

    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);  
    }
};