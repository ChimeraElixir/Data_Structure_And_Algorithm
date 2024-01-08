int BinarySearch(vector<int>& nums,int target){
    int lo=0,hi=nums.size()-1;
    int mid = lo + (hi - lo)/2;
    while( lo <= hi){
        if(nums[mid]==target){
            return mid;
        }
        else if( target > nums[mid]){
            lo = mid + 1;
        }
        else if(target < nums[mid]){
            hi = mid - 1; 
        }
        mid = lo + (hi - lo)/2;
    }

    return -1;
}