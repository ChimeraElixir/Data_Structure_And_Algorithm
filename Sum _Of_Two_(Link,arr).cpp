#include <bits/stdc++.h> 
void rotate(vector<int> &ans){
	int lo=0;
	int hi=ans.size()-1;
	while(lo<hi){
		swap(ans[lo++],ans[hi--]);
	}
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	int i=n-1;
	int j=m-1;
	int carry=0;
	vector<int> ans;
	while(i>=0 || j>=0){
		int val1=(i>=0)?a[i]:0;
		int val2=(j>=0)?b[j]:0;
		int sum=val1+val2+carry;
		ans.push_back(sum%10);
		carry=sum/10;
		i--;j--;
	}
	while(carry!=0){
		ans.push_back(carry%10);
		carry/=10;
	}
	
	rotate(ans);
	return ans;
}
