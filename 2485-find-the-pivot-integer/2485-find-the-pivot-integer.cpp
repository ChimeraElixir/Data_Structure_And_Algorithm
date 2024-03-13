class Solution {
public:
    int pivotInteger(int n) {
        double x=sqrt(((n*n)+n)/2);
        double fractional = x - static_cast<int>(x);

        if(fractional!=0.0){
            return -1;
        }
        return int(x);
    }
};