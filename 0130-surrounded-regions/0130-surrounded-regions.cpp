class Solution {
    private:
        void dfs(int row ,int col ,vector<vector<char>>& board,vector<vector<int>>& visited ,int n ,int m){
            visited[row][col]=1;

            int i[] = {1,0,-1,0};
            int j[] = {0,1,0,-1};

            for(int k=0;k<4;k++){
                int nrow = row + i[k];
                int ncol = col + j[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol] == 'O'  && !visited[nrow][ncol]){
                    dfs(nrow,ncol,board,visited,n,m);
                }
            }
        }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m =board[0].size();

        vector<vector<int>> visited(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(!visited[i][j] && board[i][j]=='O'){
                        dfs(i,j,board,visited,n,m);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};