class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int ans = 0 ;
        int n = arr.size();
        int MOD = 1000000007;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                int element = st.top();st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();

                int left = element - pse;
                int right = nse - element;
                ans = (ans + (left * 1LL * right * 1LL * arr[element]) % MOD) % MOD ;
                
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty()?-1:st.top();

            int left = element - pse;
            int right = nse - element;

            ans = (ans + (left * 1LL * right * 1LL * arr[element]) % MOD) % MOD ;
        }

        return ans;

    }
};