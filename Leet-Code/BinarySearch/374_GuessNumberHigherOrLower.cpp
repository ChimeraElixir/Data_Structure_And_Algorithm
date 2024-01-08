/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int BinarySearch(int n){
        int lo=1,hi=n;
        int mid = lo + (hi - lo)/2;
        while( lo <= hi){
            int guessed = guess(mid);
            if(guessed == 0){
                return mid;
            }
            else if( guessed == 1){
                lo = mid + 1;
            }
            else if(guessed == -1){
                hi = mid - 1; 
            }
            mid = lo + (hi - lo)/2;
        }

        return -1;
    }

    int guessNumber(int n) {
        return BinarySearch(n);    
    }
};