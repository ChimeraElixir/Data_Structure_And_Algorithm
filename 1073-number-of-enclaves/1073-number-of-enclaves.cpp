class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        
        for( int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j == 0 || j==m-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        visited[i][j] = 1;
                    }
                }
            }
        }
        int i[] = {1,0,-1,0};
        int j[] = {0,1,0,-1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for( int k=0;k<4;k++){
                int nrow = row + i[k];
                int ncol = col + j[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }
        
        return count; 
    }
};