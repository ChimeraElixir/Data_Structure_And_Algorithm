class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1){
            return -1;
        }
        vector<vector<int>> vis(n,vector<int> (m,0));

        queue<pair<int,pair<int,int>>> q;

        q.push({1,{0,0}});
        vis[0][0] = 1;


        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            if(row == n-1 && col==m-1){
                return dist;
            }
            q.pop();

            for(int i = -1 ; i<=1 ; i++){
                for(int j = -1 ; j<=1 ;j++){
                    int nrow = row + i;
                    int ncol = col + j;
                    if(nrow>=0 && nrow <n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && !vis[nrow][ncol] ){
                        vis[nrow][ncol] = 1;
                        q.push({dist+1,{nrow,ncol}});
                    }
                }
            }
        }

        return -1;
    }
};