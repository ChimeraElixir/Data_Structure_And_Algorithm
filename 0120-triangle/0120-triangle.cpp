class Solution {
public:

    int solve(int row,int col ,vector<vector<int>>& triangle ,vector<vector<int>>&dp){
        if(col < 0 || col > row) return 1e9;
        if(row == 0) return triangle[0][0];

        if(dp[row][col]!=-1) return dp[row][col];


        int up = triangle[row][col] + solve(row-1,col,triangle,dp);
        int leftDiagonal = triangle[row][col] + solve(row-1,col-1,triangle,dp);

        return dp[row][col] = min(up,leftDiagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int mini = INT_MAX;
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            int ans = solve(n-1,i,triangle,dp);
            mini =  min(mini,ans);
        }
        return mini;

    }
};