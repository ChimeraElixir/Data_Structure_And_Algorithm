class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue <pair<int,int>> q;

        int di[] = {1,0,-1,0};
        int dj[] = {0,+1,0,-1};
 
        int prev_color= image[sr][sc];

        q.push({sr,sc});
        ans[sr][sc] = color;
        vis[sr][sc] = 1;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                    int nrow = row + di[k];
                    int ncol = col + dj[k];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == prev_color && !vis[nrow][ncol]){
                        ans[nrow][ncol] = color;
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
            }
                
             
        }

        return ans;
    }
};