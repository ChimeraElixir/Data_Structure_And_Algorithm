class Solution {
public:

    int solve(int m,int n,vector<vector<int>> &vis,vector<int> &di,vector<int> &dj,vector<vector<int>> &dp){

        if(m < 0 || n< 0 ){
            return 0;
        }
        if(m==0 && n==0){
            return 1;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }


        int count = 0;

        for(int i=0;i<2;i++){
            int idx = m + di[i];
            int jdx = n + dj[i];

            if( idx>=0 && jdx>=0 && !vis[idx][jdx]){
                vis[idx][jdx] = 1;
                count+=solve(idx,jdx,vis,di,dj,dp);
                vis[idx][jdx] = 0;
            }

        }
        return dp[m][n] = count;


    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> vis(m,vector<int> (n,0));
        // vector<int> di = {-1,0};
        // vector<int> dj = {0,-1};
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // return solve(m-1,n-1,vis,di,dj,dp);

        //tabulation 
        // vector<int> di = {-1,0};
        // vector<int> dj = {0,-1};
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[0][0]=1;
        // for (int i = 1; i < m; i++) {
        //     dp[i][0] = 1; // Only one way to reach cells in the first column
        // }
        // for (int j = 1; j < n; j++) {
        //     dp[0][j] = 1; // Only one way to reach cells in the first row
        // }

        for( int i = 0; i < m; i++){
            for(int j = 0;j < n; j++){
                // int count = 0;
                // for(int k=0;k<2;k++){
                    // int idx = i + di[k];
                    // int jdx = j + dj[k];
                    // if(i == 0 && j==0) dp[i][j]=1;
                    if (i>0) dp[i][j]+= dp[i-1][j];
                    if (j>0) dp[i][j]+= dp[i][j-1];

                    // if( idx>0 && jdx>0 ){
                    //     count+=dp[idx][jdx];
                    // }

                // }
                // dp[i][j]=count;
            }
        }
        return dp[m-1][n-1];


    }
};