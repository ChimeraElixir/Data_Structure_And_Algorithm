class Solution {
public:
    vector<int> nextSmallestElement(vector<int> & arr,int n){
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallestElement(vector<int> & arr,int n){
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse =nextSmallestElement(arr,n);
        vector<int> pse =prevSmallestElement(arr,n);
        int ans = 0;
        int MOD = 1000000007;
        
        for(int i=0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            ans = (ans + ((left *1LL* right) *1LL * arr[i]) % MOD)%MOD;
        }
        return ans;
    }
};