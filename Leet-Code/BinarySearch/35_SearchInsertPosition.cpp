class Solution {
public:
    int ModifiedBinarySearch(vector<int>& nums,int target){
        int lo=0,hi=nums.size()-1;
        int mid = lo + (hi - lo)/2;
        while( lo <= hi){
          
            if (target == nums[mid]){
                return mid;
            }
            else if( target > nums[mid]){
                lo = mid + 1;
            }
            else {
                hi = mid - 1; 
            }
            mid = lo + (hi - lo)/2;
        }

        return lo;
    }

    int searchInsert(vector<int>& nums, int target) {
        return ModifiedBinarySearch(nums,target);
    }
};