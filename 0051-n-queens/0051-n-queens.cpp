class Solution {
public:
    bool check(int i, int j, int n, vector<string>& temp) {
    int row = i, col = j;

    // Check upper left diagonal
    while (row >= 0 && col >= 0) {
        if (temp[row][col] == 'Q') {
            return false;
        }
        row--; col--;
    }

    row = i; col = j;

    // Check upper right diagonal
    while (row >= 0 && col < n) {
        if (temp[row][col] == 'Q') {
            return false;
        }
        row--; col++;
    }

    row=i;
    col =j;

    while(row>=0){
        if(temp[row][col]=='Q'){
            return false;
        }
        row--;
    }

    return true;
}


    void solve(int idx , int n,vector<vector<string>> &ans,vector<string> &temp ){
        if(idx==n ){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){

            if( check(idx,i,n,temp) ){

                temp[idx][i]='Q';
                solve(idx+1,n,ans,temp);
                temp[idx][i]='.';
                
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int i=0;
        vector<vector<string>> ans;
        vector<string> temp (n,string (n,'.'));
        solve(i,n,ans,temp);
        return ans;
    }
};