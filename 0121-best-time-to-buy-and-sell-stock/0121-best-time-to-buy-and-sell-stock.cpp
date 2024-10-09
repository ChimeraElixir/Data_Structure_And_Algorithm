class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans = 0;
        int left = 0;
        int right = 0;

        for(int i=0;i<arr.size();i++){
            if(arr[i]<arr[left]){
                left = i;
                right = i;
            }
            else if(arr[i]>arr[right]){
                right = i;
            }
            ans = max(ans,arr[right]-arr[left]);
        }
        return ans;
    }
};