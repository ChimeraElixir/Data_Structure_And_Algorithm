class Solution {
public:
    int solve(vector<vector<int>> &dp,vector<int>&dx,vector<int>& dy,int x, int y,int m, int n){
        if (x == m-1 && y == n-1){
            return 1;
        }

        if(dp[x][y]!= -1){
            return dp[x][y];
        }

        int ways = 0;


        for(int i = 0;i<2;i++){
            int ndx = x + dx[i];
            int ndy = y + dy[i];

            if(ndx>=0 && ndx<m && ndy>=0 && ndy<n){
                ways += solve(dp,dx,dy,ndx,ndy,m,n) ;
            }
        }

        return dp[x][y] = ways;
    }
    int uniquePaths(int m, int n) {

        //Memoiation 

        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // vector<int> dx = {+1,0};
        // vector<int> dy = {0,+1};

        // return solve(dp,dx,dy,0,0,m,n);


        //Tabulation

        vector<vector<int>> dp(m,vector<int>(n,0));

        dp[0][0] = 1;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){

                if( i > 0 && j > 0){
                    dp[i][j] += dp[i-1][j] + dp[i][j-1];
                }
                
                else if(i > 0){
                    dp[i][j] += dp[i-1][j] ;
                }
                else if(j > 0){
                    dp[i][j] += dp[i][j-1];
                }

            }
        }

        return dp[m-1][n-1];
    }
};