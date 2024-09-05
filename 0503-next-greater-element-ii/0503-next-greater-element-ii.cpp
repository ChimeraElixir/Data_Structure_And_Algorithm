class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, -1);  // Initialize all elements with -1 (default next greater element is -1)
        

        for (int i = 2 * n - 1; i >= 0; i--) {

            int circularIndex = i % n;
            

            while (!st.empty() && st.top() <= nums[circularIndex]) {
                st.pop();
            }
            

            if (!st.empty()) {
                nge[circularIndex] = st.top();
            }
            
            
            st.push(nums[circularIndex]);
        }
        
        return nge;
    }
};