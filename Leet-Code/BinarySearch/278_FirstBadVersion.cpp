// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int FirstBadVersion(int n){
        int lo = 1,hi = n;
        int mid = lo + (hi - lo)/2;
        int ans = -1 ;
        while( lo <= hi){
            if(isBadVersion(mid)==true){
                ans = mid;
                hi = mid -1;
            }
            
            else if(isBadVersion(mid)==false){
                lo = mid + 1; 
            }
            mid = lo + (hi - lo)/2;
        }

        return ans;
    }

    int firstBadVersion(int n) {
        return FirstBadVersion(n);
    }
};