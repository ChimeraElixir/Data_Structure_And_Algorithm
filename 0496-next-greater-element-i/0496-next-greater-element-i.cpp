class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> st;
        vector<int> nge(nums2.size(),-1);
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[i]>st.top() ){
                st.pop();
            }
            if(st.empty()){
                nge[i]=-1;
            }
            else{
                nge[i]=st.top();
            }
            st.push(nums2[i]);

        }
        vector<int> ans(nums1.size(),0);
        for(int i=0;i<nums1.size();i++){
            auto j = find(nums2.begin(),nums2.end(),nums1[i]);
            int index = j-nums2.begin();
            ans[i]=nge[index];
        }
        return ans;
    }
};