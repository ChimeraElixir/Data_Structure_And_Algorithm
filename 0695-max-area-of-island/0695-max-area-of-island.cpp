class Solution {
    private:
    int dfs(int row,int col ,vector<vector<int>> &visited,vector<vector<int>>& grid,int n,int m){
        
        visited[row][col] = 1;

        int i[] = {1,0,-1,0};
        int j[] = {0,1,0,-1};
        int area = 1;

        for(int k=0;k<4;k++){
            int nrow = row + i[k];
            int ncol = col + j[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]){
                 area+= dfs(nrow,ncol,visited,grid,n,m);
            }

        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int> (m,0));
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]){
                    ans=max(ans,dfs(i,j,visited,grid,n,m));
                }
            }
        }
        for(int i = 0;i< n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !visited[i][j]){
                    return 0;
                }
            }
        }
        return ans;
    }
};