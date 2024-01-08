class Solution {
public:
    int FirstPosition(vector<int>& nums,int target){
        int lo=0,hi=nums.size()-1;
        int mid = lo + (hi - lo)/2;
        int ans = -1 ;
        while( lo <= hi){
            if(nums[mid]==target){
                ans = mid;
                hi = mid -1;
            }
            else if( target > nums[mid]){
                lo = mid + 1;
            }
            else if(target < nums[mid]){
                hi = mid - 1; 
            }
            mid = lo + (hi - lo)/2;
        }

        return ans;
    }

    int LastPosition(vector<int>& nums,int target){
        int lo=0,hi=nums.size()-1;
        int mid = lo + (hi - lo)/2;
        int ans = -1;
        while( lo <= hi){
            if(nums[mid]==target){
                ans = mid;
                lo = mid + 1;
            }
            else if( target > nums[mid]){
                lo = mid + 1;
            }
            else if(target < nums[mid]){
                hi = mid - 1; 
            }
            mid = lo + (hi - lo)/2;
        }
        
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector < int > v;
        v.push_back(FirstPosition(nums,target));
        v.push_back(LastPosition(nums,target));
        return v;
    }


};