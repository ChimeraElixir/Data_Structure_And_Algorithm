class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>  visited(n,vector<int> (m,0));

        vector<int> di = {1,0,-1,0};
        vector<int> dj = {0,1,0,-1};

        queue<pair<int,pair<int,int>>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 ){
                    q.push({0,{i,j}});  
                    visited[i][j] = 2;
                }
            }

        }
        int tm=0;
        while(!q.empty()){
            int time = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            tm = max(tm,time);
            q.pop();

            for(int k = 0; k<4;k++){
                int nrow = row + di[k];
                int ncol = col + dj[k];
                if(nrow>=0 && nrow <n && ncol>=0 && ncol <m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                    q.push({time+1,{nrow,ncol}});
                    visited[nrow][ncol] = 2;
                    grid[nrow][ncol] = 2;

                }  
            }

        }
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};