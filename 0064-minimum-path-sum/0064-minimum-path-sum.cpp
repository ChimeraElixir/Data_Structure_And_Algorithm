class Solution {
public:
    int solve(vector<vector<int>> &dp,vector<int>&dx,vector<int>& dy,int x, int y,int m, int n,vector<vector<int>>& grid){

        if (x == m-1 && y == n-1){
            return grid[m-1][n-1];
        }

        if(dp[x][y]!= -1){
            return dp[x][y];
        }

        int ways = INT_MAX;


        for(int i = 0;i<2;i++){
            int ndx = x + dx[i];
            int ndy = y + dy[i];

            if(ndx>=0 && ndx<m && ndy>=0 && ndy<n){
                ways = min(ways, grid[x][y] + solve(dp,dx,dy,ndx,ndy,m,n,grid)) ;
            }
        }

        return dp[x][y] = ways;
    }
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();


        vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<int> dx = {+1,0};
        vector<int> dy = {0,+1};

        return solve(dp,dx,dy,0,0,m,n,grid);
    }
};