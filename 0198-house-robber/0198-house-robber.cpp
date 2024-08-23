class Solution {
public:
    int solve(int n, vector<int>& nums,vector<int> &dp){

        if(n==0){
            return nums[n];
        }
        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];


        int right = solve(n-2,nums,dp) + nums[n];
        int left = solve(n-1,nums,dp) ;

        return dp[n] = max(left,right);

    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[1],nums[0]);
        }
        vector<int> dp(n,0);
        // return solve(n-1,nums,dp);


        //Tabluation
        // dp[0]=nums[0];

        // for(int i=1;i<n;i++){
        //     int take = nums[i];
        //     if(i>1) take+= dp[i-2];
        //     int notTake = dp[i-1];
        //     dp[i]=max(take,notTake);
        // }
        // return dp[n-1];


        //space Optimization
        int prev =nums[0];
        int prev2= 0;

        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+= prev2;
            int notTake = prev;
            int curr=max(take,notTake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};