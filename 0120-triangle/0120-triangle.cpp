class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[triangle.size()-1].size();

        vector<vector<int>> dp(n,vector<int>(m,1e9));

        dp[0][0] = triangle[0][0];

        for(int i = 0 ; i < triangle.size() ; i++){
            for(int  j = 0 ; j < triangle[i].size() ; j++){
                if(i > 0) dp[i][j] = min(dp[i][j],dp[i-1][j] + triangle[i][j]);
                if(j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + triangle[i][j]);
            }
        }
        
        int mini = 1e9;

        for(int i = 0 ; i < triangle[triangle.size()-1].size();i++ ){
            mini = min(mini,dp[n-1][i]); 
        }

        return mini;
        

    }
};