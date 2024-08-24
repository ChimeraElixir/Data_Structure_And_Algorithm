class Solution {
public:
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

        return dp[m][n]=count;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        vector <int> di = {-1,0}; 
        vector <int> dj  = {0,-1};
        vector <vector<int>> dp (m,vector<int> (n,-1)); 
        return solve(m-1,n-1,obstacleGrid,di,dj,dp);
    }
};