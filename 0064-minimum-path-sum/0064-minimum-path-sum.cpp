class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& grid,vector<vector<int>> &dp){

        if(m==0 && n==0){
            return grid[0][0];
        }

        if(m<0 || n<0){
            return 40001;
        }

        if(dp[m][n]!=-1) return dp[m][n];
        
        int up = + grid[m][n] + solve(m-1,n,grid,dp) ;
        int left = grid[m][n] + solve(m,n-1,grid,dp) ;

        return dp[m][n] = min(up,left);

    }

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp (m,vector<int> (n,-1));
        // return solve(m-1,n-1,grid,dp);

        vector<vector<int>> dp (m,vector<int> (n,40001));

        dp[0][0]=grid[0][0];

        for( int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int left = dp[i][j];
                int right =dp[i][j];
                if(i>0) left = dp[i-1][j]+grid[i][j];
                if(j>0) right = dp[i][j-1]+grid[i][j];

                dp[i][j]=min(left,right);
            }

        }
        return dp[m-1][n-1];


    }
};