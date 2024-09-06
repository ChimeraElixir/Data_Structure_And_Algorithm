class Solution {
public:
    vector<int> NSE(vector<int>& arr,int n){
        stack <int> st;
        vector<int> ans (n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int>& arr,int n){
        stack <int> st;
        vector<int> ans (n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = NSE(arr,n);
        vector<int> pse = PSE(arr,n);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, arr[i] * (nse[i] - pse[i]-1));
        }
        return ans;
    }
};