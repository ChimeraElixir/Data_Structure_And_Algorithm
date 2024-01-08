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

    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector < int > v;
        int start = FirstPosition(nums,target);
        int last = LastPosition(nums,target);
        if( start == -1 && last ==-1){
            return v;
        }
        for( int i = start ; i <= last ; i++ ){
            v.push_back(i);
        }
        return v;
    }
};