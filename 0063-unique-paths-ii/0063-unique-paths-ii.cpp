class Solution {
public:
    // int solve(int m, int n , vector<vector<int>>& arr,vector<int> &di,vector<int> &dj,vector<vector<int>> &dp){

    //     if(m==0 && n==0) return 1;

    //     if(m<0 || n < 0) return 0;

    //     if(dp[m][n]!=-1) return dp[m][n];

    //     int left =0;
    //     int right =0;

    //     if(arr[m][n]==0){
    //         int left = solve(m-1,n,arr,di,dj,dp);
    //         int right = solve(m,n-1,arr,di,dj,dp);
    //     }


    //     return dp[m][n]= left+right ;
    // }



    int solve(int m, int n , vector<vector<int>>& arr,vector<int> &di,vector<int> &dj,vector<vector<int>> &dp){

        if(m==0 && n==0) return 1;

        if(m<0 || n < 0) return 0;

        if(dp[m][n]!=-1) return dp[m][n];

        int count = 0;

        for(int k=0;k<2;k++){
            int idx = m + di[k];
            int jdx = n + dj[k];

            if(idx>=0 && jdx>=0 && !arr[m][n]){
                count += solve(idx,jdx,arr,di,dj,dp);
            }
        }

        

        return dp[m][n]= count ;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        // if(obstacleGrid[0][0]==1) return 0;

        // int m = obstacleGrid.size();
        // int n = obstacleGrid[0].size();

        // vector <int> di = {-1,0}; 
        // vector <int> dj  = {0,-1};

        // vector <vector<int>> dp (m,vector<int> (n,-1)); 

        // return solve(m-1,n-1,obstacleGrid,di,dj,dp);

        // tablulation

        if(obstacleGrid[0][0]==1) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector <vector<int>> dp (m,vector<int> (n,0)); 

        dp[0][0]=1;

        for( int i=0;i<m;i++){
            for( int j = 0 ; j<n ; j++){
                
                if(obstacleGrid[i][j] == 0){
                    if(i>0) dp[i][j] += dp[i-1][j];
                    if(j>0) dp[i][j] += dp[i][j-1];
                }
                
            }
        }
        return dp[m-1][n-1];


    }
};