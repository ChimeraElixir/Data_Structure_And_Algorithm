class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int m, int n) {
        vis[row][col] = 1;

       
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        
        for (int i = 0; i < 4; i++) {
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, vis, grid, m, n);  
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> vis (m,vector<int> (n,0));

        for(int i=0;i<m;i++){
            for(int j=0 ;j < n ; j++ ){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,vis,grid,m,n);
                    count++;
                }
            }
        }
        return count;
        
    }
};