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
        vector<vector<int>> vis(m,vector<int> (n,0));
        vector<int> di = {-1,0};
        vector<int> dj = {0,-1};
        vector<vector<int>> dp(m,vector<int> (n,-1));

        return solve(m-1,n-1,vis,di,dj,dp);
    }
};