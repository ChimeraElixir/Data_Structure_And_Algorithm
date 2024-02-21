bool check(vector<int> &arr,int limit,int mid){
	int count=0;
	for(auto i:arr){
		count+=ceil(1.0*i/mid);
	}
	return count<=limit;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	int s=*min_element(arr.begin(),arr.end());
	int e=*max_element(arr.begin(),arr.end());

	while(s<=e){
		int mid=s+(e-s)/2;

		if(check(arr,limit,mid)){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return s;
}
