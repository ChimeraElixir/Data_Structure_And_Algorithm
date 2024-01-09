class Solution {
public:
    int Peak( vector <int>&arr ){
        int lo = 0;
        int hi = arr.size()-1;

        int mid = lo + (hi-lo)/2;
             
        while (lo < hi){
            if(arr[mid] < arr[mid+1]){
                lo = mid + 1;
            }
            else if(arr[mid] < arr[mid-1]){
                hi = mid - 1 ;
            }
            else{
                hi = mid;
            }
            mid = lo + (hi-lo)/2;
        }
        return lo;
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        return Peak(arr);
    }
};