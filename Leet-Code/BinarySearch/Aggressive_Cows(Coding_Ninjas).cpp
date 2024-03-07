bool possible(vector<int> &stalls, int k,int mid,int n){

    int count=1;
    int last=stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i]-last>=mid){
            count++;
            last=stalls[i];
        }
        if(count>=k){
            return true;
        }
    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int s=1;
    int e=stalls[n-1]-stalls[0];

    while(s<=e){
        int mid=s+(e-s)/2;
        if(possible(stalls,k,mid,n)){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return e;
}
