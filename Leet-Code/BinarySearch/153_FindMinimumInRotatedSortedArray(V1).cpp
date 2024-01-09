class Solution {
public:
    int pivot(vector < int > &arr){
        int lo=0,hi=arr.size()-1;
        int mid = lo + (hi-lo)/2;
        int ans = INT_MAX;
        while(lo < hi){
            if(arr[mid] >= arr[lo]){
                ans = min(ans,arr[lo]);
                lo = mid + 1;
            }
            // This can be commented out 
            else if(arr[mid] < arr[hi]){
                ans = min(ans,arr[mid]);
                hi = mid-1;

            }
            else{
                hi=mid;
            }
            
           mid = lo + (hi-lo)/2; 

        }
        return min(ans,arr[lo]);
    }
    int findMin(vector<int>& nums) {
        int a=pivot(nums);
        return a;

    }
};