class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int leftMax = 0;
        int rightMax = 0;
        int i = 0;
        int j = n-1;
        int ans = 0;
        while(i<=j){
            if(arr[i]<=arr[j]){
                if(leftMax>arr[i]){
                    ans+= leftMax - arr[i];
                }
                else{
                    leftMax = arr[i];
                }
                i++;
            }
            else{
                if(rightMax>arr[j]){
                    ans+= rightMax - arr[j];
                }
                else{
                    rightMax = arr[j];
                }
                j--;
            }
        }
        return ans;
    }
};