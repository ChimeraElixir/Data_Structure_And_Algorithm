int check(vector<int> &weights,int mid){
   int days = 1;
    int sum = 0;
    for (int weight : weights) {
        sum += weight;
        if (sum > mid) {
            days++;
            sum = weight;
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int s=*max_element(weights.begin(), weights.end());
    int e=accumulate(weights.begin(), weights.end(), 0);;
    while(s<e){
        int mid=s+(e-s)/2;
        int res=check(weights,mid);
        if(res<=d){
            e=mid;
        }
        else{
            s=mid+1;
        }
    }
    return s;
}
