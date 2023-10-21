// vector<string> subString(int n,string &s) 
// {
//     // Pick starting point
// 	vector<string> v;
// 	string g;
//     for (int len = 1; len <= n; len++) 
//     {    
//         // Pick ending point
//         for (int i = 0; i <= n - len; i++) 
//         {
//             //  Print characters from current
//             // starting point to current ending
//             // point.  
//             int j = i + len - 1;            
//             for (int k = i; k <= j; k++) 
// 				g+=s[k];
                
//             v.push_back(g);
// 			g="" ;
		
//         }
//     }
// 	return v;
// }

vector<string> subString(string &str)
{
	vector<string> v;
    // First loop for starting index
    for (int i = 0; i < str.length(); i++) {
        string subStr;
        // Second loop is generating sub-string
        for (int j = i; j < str.length(); j++) {
			if(str[i]==str[j]){
            	subStr += str[j];
				v.push_back(subStr);
				

			}
			else{
				break;

			}
            
        }
    }
	
	return v;
}
// void subString(string str)
// {
 
//     // First loop for starting index
//     for (int i = 0; i < str.length(); i++) {
//         string subStr;
//         // Second loop is generating sub-string
//         for (int j = i; j < str.length(); j++) {
//             subStr += str[j];
//             cout << subStr << endl;
//         }
//     }
// }
 

int longestSpecialString(int n, string &s) {
	// Write your code here.
	map<string,int> m;
	map<string,int> m2;
	int max_=INT_MIN;

	vector<string> v=(subString(s));
	// subString(s);
	
	for(auto i:v){
		m[i]++;
	}
	// for (auto i:m){
	// 	if(i.second>1){
	// 		m2[i.first]=i.second;
	// 	}
	// }
	// cout<<endl;
	// cout<<"M1"<<endl;
	// for(auto i:m){
	// 	cout<<i.first<<i.second<<endl;
	// }
	// cout<<endl;
	// cout<<"M2"<<endl;
	// for(auto i:m2){
	// 	cout<<i.first<<i.second<<endl;
	// }
	
	// for(auto i:m){
	// 		if(i.second>1){
	// 			int x=i.first.size();
	// 			int cou=(count(i.first.begin(),i.first.begin(),'i.first[0]'));
	// 			if(cou==i.first.size()){
	// 				max_=max(max_,x);

	// 			}

	// 		}
		
	// }
	for(auto i:m){
		if(i.second>1){
			int x=i.first.size();
			max_=max(max_,x);
		}
	}

	if(max_==INT_MIN){
		return 0;
	} 
	// cout<<endl;
	return max_;
	// return 0;



	


	// int i=0;
	// int count=0;
	// for(int i=0;i<n-1;i++){
		
	// 	if(s[i]!=s[i+1]){
	// 		string k=(s[i]*count);
	// 		m[k]++;
	// 		count=1;
	// 		continue;
	// 	}
	// 	count++;
	// }
	// for(auto i:m){
	// 	if (i.second>1){
	// 		return 1;
	// 	}
	// }
	return 0;
	
}