class Solution {
public:
    bool solve(int n, int k, vector<int> &arr,vector<vector<int>>&dp){
        if(k==0){
            return true;
        }
        if(n<0 || k < 0){
            return false;
        }

        if(dp[n][k]!=-1){
            return dp[n][k];
        }

        //pick 
        int pick = solve(n-1,k-arr[n],arr,dp);
        int notpick = solve(n-1,k,arr,dp);

        return dp[n][k] = (pick || notpick);
    }
    bool subsetSumToK(int n, int k, vector<int> &arr) {

    // Write your code here.
    // vector<vector<int>> dp(n,vector<int>(k+1,-1));

    // return solve(n-1,k,arr,dp);

    // Tabulation 

    // vector<vector<bool>> dp(n,vector<bool>(k+1,false));

    // for(int i=0 ;i < n;i++){
    //     dp[i][0] = true;
    // }

    // if(arr[0]<=k){
    //     dp[0][arr[0]] = true;
    // }

    // for(int i = 1 ; i < n ; i++){
    //     for(int j = 1 ; j < k+1 ;j++){
    //         bool pick = false;
    //         if(j-arr[i]>=0){
    //             pick = dp[i-1][j-arr[i]] ;
    //         }

    //         bool notpick = dp[i-1][j];

    //         dp[i][j] = ( pick || notpick );
    //     }
    // }

    // return dp[n-1][k];


    //Space Optimization

    vector<bool> dp(k + 1, false);

    dp[0] = true;

    if(arr[0] <= k) {
        dp[arr[0]] = true;
    }

    for(int i = 1; i < n; i++) {
        for(int j = k; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    return dp[k];


}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totsum = 0;

        for(int i=0;i<n;i++){
            totsum += nums[i];
        }

        if(totsum & 1 ) return false;

        return subsetSumToK(n,totsum/2,nums);

    }
};