class Solution {
public:

    int solve(int row,int col ,vector<vector<int>>& triangle ,vector<vector<int>>&dp){
        if(col < 0 || col > row) return 1e9;
        if(row == 0) return triangle[0][0];

        if(dp[row][col]!=-1) return dp[row][col];


        int up = triangle[row][col] + solve(row-1,col,triangle,dp);
        int leftDiagonal = triangle[row][col] + solve(row-1,col-1,triangle,dp);

        return dp[row][col] = min(up,leftDiagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        //******* Memoization ********//
        
        // int mini = INT_MAX;
        // int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
       
        // for(int i=0;i<n;i++){
        //     int ans = solve(n-1,i,triangle,dp);
        //     mini =  min(mini,ans);
        // }
        // return mini;


        //****** Tabluation *******//
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,1e5));
        dp[0][0]=triangle[0][0];

        for(int i=1;i<n;i++){
            for(int j=0;j<i+1;j++){

                int up = dp[i][j];
                int leftup = dp[i][j];
                if(j<i) up = dp[i-1][j]; 
                if(j>0)  leftup = dp[i-1][j-1];

                dp[i][j] = triangle[i][j] + min(up,leftup);
                
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};