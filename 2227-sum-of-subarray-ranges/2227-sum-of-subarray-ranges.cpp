class Solution {


public:
    vector<long long> NSE(vector<int>& arr,int n){
        stack <long long> st;
        vector<long long> ans (n,n);
        for(long long i=n-1;i>=0;i--){
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
    vector<long long> PSEE(vector<int>& arr,int n){
        stack <long long> st;
        vector<long long> ans (n,-1);
        for(long long i=0;i<n;i++){
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
    vector<long long> NGE(vector<int>& arr,int n){
        stack <long long> st;
        vector<long long> ans (n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>=arr[st.top()]){
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
    vector<long long> PGEE(vector<int>& arr,int n){
        stack <long long> st;
        vector<long long> ans (n,-1);
        for(long long i=0;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
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
    long long sumOfSubarrayMin(vector<int>& arr,int n){
        vector<long long> nse = NSE(arr,n);
        vector<long long> psee = PSEE(arr,n);
        long long ans = 0;

        for(long long i = 0 ;i < n ;i++){
            long long left = i - psee[i];
            long long right = nse[i]-i;

            ans += (left * 1LL * right) * arr[i];

        }
        return ans;
    }
    long long sumOfSubarrayMax(vector<int>& arr,int n){
        vector<long long> nge = NGE(arr,n);
        vector<long long> pgee = PGEE(arr,n);
        long ans = 0;

        for(int i = 0 ;i < n ;i++){
            long long left = i - pgee[i];
            long long right = nge[i]-i;

            ans += (left * 1LL * right) * arr[i];

        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size();
        long long max = sumOfSubarrayMax(nums,n);
        long long min = sumOfSubarrayMin(nums,n);

        return max - min ;
    }
};