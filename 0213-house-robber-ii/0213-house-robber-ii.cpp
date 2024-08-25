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
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        vector<int> dp1(nums.size()-1,-1);
        vector<int> temp1(nums.begin()+1,nums.end());

        vector<int> dp2(nums.size()-1,-1);
        vector<int> temp2(nums.begin(),nums.end()-1);

        return max(solve(temp1.size()-1,temp1,dp1),solve(temp2.size()-1,temp2,dp2));

    }
};