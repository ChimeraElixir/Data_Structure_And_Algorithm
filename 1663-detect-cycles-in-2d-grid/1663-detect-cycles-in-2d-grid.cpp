class Solution {
    private:
    bool bfs(int row,int col ,vector<vector<char>>& grid,vector<vector<int>>& visited,int character,int n,int m){

        int i[] = {1,0,-1,0};
        int j[] = {0,1,0,-1};


        queue<pair<pair<int, int>, pair<int, int>>> q; ;
        q.push({{row,col},{-1,-1}});
        visited[row][col] = 1;

        while(!q.empty()){
            int currRow = q.front().first.first;
            int currCol = q.front().first.second;
            int prevRow = q.front().second.first;
            int prevCol = q.front().second.second;
            q.pop();

            for(int k = 0 ;k<4;k++){
                int  nrow = currRow + i[k];
                int  ncol = currCol + j[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==character){
                    if(!visited[nrow][ncol]){
                        q.push({{nrow,ncol},{currRow,currCol}});
                        visited[nrow][ncol] = 1;

                    }
                    else if(nrow != prevRow || ncol !=prevCol){
                        return true;
                    }
                }

            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n =grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    char character = grid[i][j];
                   if( bfs(i,j,grid,visited,character,n,m))return true;
                }
            }
        }
        return false;
        
    }
};