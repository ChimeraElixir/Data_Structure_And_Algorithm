class Solution {
public:

    long long binarySearch(int x){
        int s=0;
        int e=x;
        int ans=-1;

        while(s<=e){
            long long mid=s+(e-s)/2;
            if(mid*mid==x){
                return ans=mid;
            }
            if(mid*mid>x){
                e=mid-1;

            }
            else{
                s=mid+1;
                ans=mid;
            }
        }
        return ans;
    }

    int mySqrt(int x) {
        return binarySearch(x);
    }
};