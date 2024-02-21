
int checkBloom(vector<int> arr,int k,int m, int mid){
	int n=arr.size();
	int count=0;
	int bouquets=0;
	
	for(int i=0;i<n;i++){
		if(arr[i]<=mid){
			count++;
                } else {
                        bouquets += (count / k);
                        count = 0;
                }
        }
        bouquets += (count / k);
		if(bouquets>=m){
			return 1;
		}
		
        return 0;
}
int roseGarden(vector<int> arr, int k, int m)
{
	int n=arr.size();
	int s=*min_element(arr.begin(),arr.end());
	int e=*max_element(arr.begin(),arr.end());
	
	if(1LL*k*m>n){
		return -1;
	}

	while(s<=e){
		int mid=s+(e-s)/2;
		int check=checkBloom(arr,k,m,mid);
		
		if(check==1){
			e=mid-1;
		}
		
		else{
			s=mid+1;
		}
	}
	return s;
}

