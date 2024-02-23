class Solution {
private:
    int function(vector<vector<int>>& list, int src, int dst, int k, int n, vector<vector<int>>& dp) {
        if (k < 0) // Base case: If stops are exhausted, return maximum value.
            return 1e9;
        if (src == dst) // Base case: If source is equal to destination, return 0.
            return 0;
        
        
        if (dp[src][k] != -1) // If already computed, return the stored value.
            return dp[src][k];

        int ans = 1e9;

        for (int i = 0; i < n; i++) {
            if (list[src][i] != -1) { // If there's a flight from src to i
                ans = min(ans, list[src][i] + function(list, i, dst, k - 1, n, dp)); // Recurse to find the cost from i to dst with one less stop
            }
        }

        return dp[src][k] = ans; // Store and return the result
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> list(n, vector<int>(n, -1));
        vector<vector<int>> dp(101, vector<int>(101, -1)); // Initialize dp with size n x k + 2

        for (auto flight : flights) {
            list[flight[0]][flight[1]] = flight[2];
        }

        int ans = function(list, src, dst, k + 1, n, dp); // Call the helper function

        return ans >= 1e9 ? -1 : ans;
    }
};
